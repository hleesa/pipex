/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:23:40 by salee2            #+#    #+#             */
/*   Updated: 2022/09/29 12:23:42 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		*pipe_fds;

	exit_if_invalid_arg(argc);
	pid = fork();
	if (pid < 0)
		exit_fork_error();
	else if (pid > 0)	// parent
		wait(0);
	else	// child
	{
		pipe_fds = make_pipe();
		pid = fork();
		if(pid < 0)
			exit_fork_error();
		else if(pid > 0) // parent
		{
			input_redirection(argv[1]);
			close(pipe_fds[READER_FD]);
			dup2(pipe_fds[WRITER_FD], STDOUT_FILENO);
			close(pipe_fds[WRITER_FD]);
			free(pipe_fds);
			run_execve(argv[2], envp);
		}
		else	// child
		{
			output_redirection(argv[4]);
			close(pipe_fds[WRITER_FD]);
			dup2(pipe_fds[READER_FD], STDIN_FILENO);
			close(pipe_fds[READER_FD]);
			free(pipe_fds);
			run_execve(argv[3], envp);
		}
	}
	return 0;
}
