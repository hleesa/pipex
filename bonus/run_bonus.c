/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:58:58 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 16:58:59 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	run_execve(char *argv, char **envp)
{
	int		i;
	char	**arg_vec;
	char	**file_list;

	arg_vec = ft_split(argv, ' ');
	file_list = get_file_list("PATH", envp, arg_vec[0]);
	i = -1;
	while (file_list[++i])
	{
		if (access(file_list[i], F_OK) == 0)
		{
			if (execve(file_list[i], arg_vec, envp) == -1)
			{
				perror("Could not execute execve");
				exit(EXIT_FAILURE);
			}
		}
	}
	return ;
}

void	run_cmd(pid_t pid, char **argv, char **envp, int arg_idx, int arg_end)
{
	int	*pipe_fds;

	pipe_fds = make_pipe();
	pid = fork();
	if (pid < 0)
		exit_fork_error();
	else if (pid > 0)
	{
		// stdin을 file로 변경,
		input_redirection(argv[1]);
		// pipe[read] 닫는다. stdout을 pipe[write]로 변경
		dup_write_fd(pipe_fds);
		// 즉, stdin : file, stdout : pipe[write],
		free(pipe_fds);
		run_execve(argv[2], envp);
	}
	else
	{
		// stdout이 file을 가리킨다.
		output_redirection(argv[4]);
		// pipe[write]를 닫는다. stdin이 pipe[read]를 가리킨다.
		dup_read_fd(pipe_fds);
		// 즉, stdin : pipe[read], stdout : file
		free(pipe_fds);
		run_execve(argv[3], envp);
	}
	return ;
}
