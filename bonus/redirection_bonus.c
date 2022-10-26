/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:58:52 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 16:58:54 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	input_redirection(char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (fd == -1)
	{
		ft_printf("pipex: %s: ", path);
		perror("");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}
//
//void	input_redirection_heredoc(char *eof)
//{
//	const char *path = "_SaLeE__TmP_";
//	const int	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);
//
//	if (fd == -1)
//	{
//		ft_printf("pipex: %s: ", path);
//		perror("");
//		exit(EXIT_FAILURE);
//	}
//	if (dup2(fd, STDIN_FILENO) == -1)
//	{
//		perror("dup2()");
//		exit(EXIT_FAILURE);
//	}
//	close(fd);
//	return ;
//}

void	output_redirection(char *path)
{
	const int	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		ft_printf("pipex: %s:", path);
		perror("");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}

void	output_redirection_append(char *path)
{
	const int	fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644);

	if (fd == -1)
	{
		ft_printf("pipex: %s:", path);
		perror("");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}

void	io_redirection(t_arg *arg)
{
	if (arg->idx == 2)
		input_redirection(arg->vec[1]);
	if (arg->idx + 2 == arg->end)
		output_redirection(arg->vec[arg->end - 1]);
	return ;
}



char *test1(char **envp)
{
	char *file = "/usr/bin/mktemp";
//	char *exec_agv[] = {"mktemp", "/tmp/pipex_tmp_XXXXXXXXXX", NULL};
	char *exec_agv[] = {"mktemp", "/var/folders/zz/zyxvpxvq6csfxvn_n000crf000363h/T/pipex_tmp_XXXXXXXXXX", NULL};
	pid_t	pid;
	int *pipe_fds = make_pipe();
	char buf[200];
	ft_memset(buf, 0, 200);
	char *ret;

	pid = fork();
	if(pid < 0)
	{
		exit_fork_error();
	}
	else if (pid > 0)
	{
		redir_r_pipe_to_stdin(pipe_fds);
//		free(pipe_fds);
		wait(0);
		read(STDIN_FILENO, buf, 100);
		ret = ft_strdup(buf);
		return (ret);
	}
	else
	{
		redir_w_pipe_to_stdout(pipe_fds);
//		free(pipe_fds);
		execve(file, exec_agv, envp);
		ft_printf("here\n");
	}
	return NULL;
}