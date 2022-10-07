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

	printf("=================================================================\n");

	char** file_list = get_file_list("PATH", envp, "ls");

	char *argVec[] = {"ls", "-l",NULL};
	int i = -1;
	while (file_list[++i])
	{
		if (execve(file_list[i], argVec, NULL) == -1) {
			perror("Could not execute execve");
		}
		printf("Oops, something went wrong!");
	}
	printf("=================================================================\n");


	(void) argc;
	(void) argv;
	(void) envp;
//	char *file = "/bin/ls";


//	char *envVec[] = {NULL};

//	while(*argv)
//	{
//		printf("%s\n", *argv);
//		++argv;
//	}
//
//	printf("Start of execve call %s:\n", file);
//	printf("====================================================\n");
//	if (execve(file, argVec, NULL) == -1) {
//		perror("Could not execute execve");
//	}
//	printf("Oops, something went wrong!");

	return 0;



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
		printf("[%d] parent send\n", getpid());
		close(pipe_fds[WRITER_FD]);

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