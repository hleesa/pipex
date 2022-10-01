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

int main()
{
	int pipe_fds[2];
	pid_t pid;
	char buf[1024];
	int wstatus;

	printf("[%d] start of function\n", getpid());
	ft_memset(buf, 0, sizeof buf);

	if (pipe(pipe_fds)) {
		perror("pipe()");
		return -1;
	}

	pid = fork();
	if (pid == 0) {
		/*
		 * child process
		 */
		close(pipe_fds[WRITER_FD]);

		read(pipe_fds[READER_FD], buf, sizeof(buf));
		printf("[%d] parent said... %s\n",getpid(), buf);

		close(pipe_fds[READER_FD]);
	} else if(pid > 0) {
		/*
		 * parent process
		 */
		close(pipe_fds[READER_FD]);

		strncpy(buf, "hello child~", sizeof (buf) - 1);
		write(pipe_fds[WRITER_FD], buf, strlen(buf));

		close(pipe_fds[READER_FD]);

		pid = wait(&wstatus);

	} else {
		/*
		 * error case
		 */
		perror("fork()");
		goto err;
	}
	return 0;

	err:
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	return -1;

}
