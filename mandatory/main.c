/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:42:54 by salee2            #+#    #+#             */
/*   Updated: 2022/11/19 20:42:55 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_arg(t_arg *arg_info, char **argv, int argc)
{
	exit_if_invalid_arg(argc);
	arg_info->vec = argv;
	arg_info->idx = 2;
	arg_info->end = argc;
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	t_arg	arg;

	init_arg(&arg, argv, argc);
	pid = fork();
	exit_if_fork_error(pid);
	if (pid > 0)
		wait(0);
	else
		run_cmd(pid, &arg, envp);
	return (0);
}
