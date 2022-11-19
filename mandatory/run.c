/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:43:27 by salee2            #+#    #+#             */
/*   Updated: 2022/11/19 20:43:28 by salee2           ###   ########.fr       */
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
	ft_printf("pipex: %s: command not found\n", argv);
	exit(EXIT_FAILURE);
}

void	run_cmd(pid_t pid, t_arg *arg, char **envp)
{
	int	*pipe_fds;

	if (arg->idx + 1 == arg->end)
		return ;
	pipe_fds = make_pipe();
	pid = fork();
	exit_if_fork_error(pid);
	if (pid > 0)
	{
		redirect_r_pipe_to_stdin(pipe_fds);
		free(pipe_fds);
		++arg->idx;
		run_cmd(pid, arg, envp);
		wait(0);
	}
	else
	{
		redirect_w_pipe_to_stdout(pipe_fds);
		io_redirection(arg);
		free(pipe_fds);
		run_execve(arg->vec[arg->idx], envp);
	}
	return ;
}
