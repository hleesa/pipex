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

void	input_redirection(char *path)
{
	const int fd = open(path, O_RDONLY);

	if(dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2()");
		exit(-1);
	}
	close(fd);
	return ;
}

void printEnvp(char **envp)
{
	printf("envp begin:===========================\n");
	int i=0;
	while(envp[i])
	{
		printf("%s\n", envp[i]);
		++i;
	}
	printf("envp end:===========================\n");
}

int main(int argc, char **argv, char **envp)
{
	int pipe_fds[2];
	pid_t pid;

	if (pipe(pipe_fds)) {
		perror("pipe()");
		return -1;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	else if (pid > 0)	// parent
	{
		wait(0);

		close(pipe_fds[WRITER_FD]);
		const int fd = open(argv[4], O_RDWR | O_CREAT, S_IRWXU);
		if(dup2(fd, STDOUT_FILENO) == -1)
		{
			perror("dup2()");
			exit(-1);
		}
		//read
		dup2(pipe_fds[READER_FD], STDIN_FILENO);
		char **arg_vec = ft_split(argv[3], ' ');
		char **file_list = get_file_list("PATH", envp, arg_vec[0]);
		int i = -1;
		while (file_list[++i])
		{
			if (access(file_list[i], F_OK) == 0)
			{
				if (execve(file_list[i], arg_vec, envp) == -1)
				{
					perror("Could not execute execve");
				}
			}
		}

		close(pipe_fds[WRITER_FD]);
	}
	else	// child
	{
		// input redirection
		close(pipe_fds[READER_FD]);
		const int fd = open(argv[1], O_RDONLY);
		if(dup2(fd, STDIN_FILENO) == -1)
		{
			perror("dup2()");
			exit(-1);
		}
		close(fd);
		//write
		dup2(pipe_fds[WRITER_FD], STDOUT_FILENO);
		char **arg_vec = ft_split(argv[2], ' ');
		char **file_list = get_file_list("PATH", envp, arg_vec[0]);
		int i = 0;
		while (file_list[++i])
		{
			if (access(file_list[i], F_OK) == 0)
			{
				if (execve(file_list[i], arg_vec, envp) == -1)
					perror("Could not execute execve");
			}
		}
		close(pipe_fds[WRITER_FD]);
	}
	(void) argc;
	return 0;
}
