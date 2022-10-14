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
	int *pipe_fds;
	pid_t pid;

	if (argc != 5)
		return EXIT_FAILURE;
	pipe_fds = make_pipe();
	pid = fork();
	if (pid < 0)
	{
		perror("fork()");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)	// parent
	{
		wait(0);
		close(pipe_fds[WRITER_FD]);
		output_redirection(argv[4]);
		dup2(pipe_fds[READER_FD], STDIN_FILENO);
		run_execve(argv[3], envp);
		close(pipe_fds[READER_FD]);
	}
	else	// child
	{
		close(pipe_fds[READER_FD]);
		input_redirection(argv[1]);
		dup2(pipe_fds[WRITER_FD], STDOUT_FILENO);
		run_execve(argv[2], envp);
		close(pipe_fds[WRITER_FD]);
	}
	free(pipe_fds);
	return 0;
}
