/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:59:38 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 15:59:39 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	perror("");
	exit(EXIT_FAILURE);
}

void	run_cmd(pid_t pid, char **argv, char **envp)
{
	int	*pipe_fds;

	pipe_fds = make_pipe();
	pid = fork();
	if (pid < 0)
		exit_fork_error();
	else if (pid > 0)
	{
		input_redirection(argv[1]);
		dup_write_fd(pipe_fds);
		free(pipe_fds);
		run_execve(argv[2], envp);
	}
	else
	{
		output_redirection(argv[4]);
		dup_read_fd(pipe_fds);
		free(pipe_fds);
		run_execve(argv[3], envp);
	}
	return ;
}
