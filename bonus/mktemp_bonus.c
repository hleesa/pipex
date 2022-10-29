/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mktemp_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:25:08 by salee2            #+#    #+#             */
/*   Updated: 2022/10/27 15:25:11 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_temp_file(char **envp)
{
	char	*temp_path;
	char	*temp_file_name;
	char	*temp_file;

	temp_path = ft_get_env("TMPDIR", envp);
	temp_file_name = "tmp.pipex.XXXXXXXXXXXXXXXXXXXX";
	temp_file = ft_strjoin(temp_path, "/");
	temp_file = ft_strjoin(temp_file, temp_file_name);
	return (temp_file);

}

void	exec_mktemp(char **envp)
{
	char	*file;
	char	*exec_agv[4];

	file = ft_strdup("/usr/bin/mktemp");
	exec_agv[0] = ft_strdup("mktemp");
	exec_agv[1] = "-u";
	exec_agv[2] = get_temp_file(envp);
	exec_agv[3] = NULL;
	execve(file, exec_agv, envp);
	perror("");
	exit(EXIT_FAILURE);
}

char	*ft_mktemp(char **envp)
{
	pid_t	pid;
	int		*pipe_fds;
	char	buf[100];

	pipe_fds = make_pipe();
	ft_memset(buf, 0, 100);
	pid = fork();
	if (pid < 0)
		exit_fork_error();
	else if (pid > 0)
	{
		redir_r_pipe_to_stdin(pipe_fds);
		free(pipe_fds);
		wait(0);
		read(STDIN_FILENO, buf, 100);
		return (ft_strdup(buf));
	}
	else
	{
		redir_w_pipe_to_stdout(pipe_fds);
		free(pipe_fds);
		exec_mktemp(envp);
	}
	return (NULL);
}
