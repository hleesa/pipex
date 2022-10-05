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

char	*ft_get_env(const char *name, char **env)
{
	while (*env)
	{
		if (ft_strncmp(name, *env, ft_strlen(name)) == 0)
			return (*(env) + ft_strlen(name) + 1);
		++env;
	}
	return (NULL);
}
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

	(void) argc;
	(void) argv;
//	char **env;
//	env = envp;
//	while (*env) {
//		printf("%s\n", *env);
//		++env;
//	}
	printf("=================================================================\n");
	char *val = getenv("PATH");
	if (val == NULL) {
		printf("not defined\n");
	} else {
		printf("PATH = %s\n", val);
	}
	printf("=================================================================\n");

	val = ft_get_env("PATH", envp);
	if (val == NULL) {
		printf("not defined\n");
	} else {
		printf("PATH = %s\n", val);
	}
	printf("=================================================================\n");

	/*
	 *
	 */

	char cmd[] = "/bin/ls";

	char *argVec[] = {"ls", "-l",NULL};
	char *envVec[] = {NULL};

	printf("Start of execve call %s:\n", cmd);
	printf("====================================================\n");
	if (execve(cmd, argVec, envVec) == -1) {
		perror("Could not execute execve");
	}
	printf("Oops, something went wrong!");

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