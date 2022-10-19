/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:58:37 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 16:58:45 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_arg(t_arg *arg_info, char **argv, int argc)
{
	if (!is_right_args(argc))
	{
		perror("invalid arg");
		exit(EXIT_FAILURE);
	}
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
	if (pid < 0)
		exit_fork_error();
	else if (pid > 0)
		wait(0);
	else
		run_cmd(pid, &arg, envp);
	return (0);
}
