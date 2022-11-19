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
	exit_if_invalid_arg(argc);
	arg_info->stdin_fd = dup(STDIN_FILENO);
	arg_info->vec = argv;
	arg_info->idx = 2;
	arg_info->end = argc;
	arg_info->is_heredoc = FALSE;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		exit_if_invalid_heredoc_arg(argc);
		arg_info->idx = 3;
		arg_info->is_heredoc = TRUE;
	}
	return ;
}

void	check_leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	t_arg	arg;

//	atexit(check_leaks);
	init_arg(&arg, argv, argc);
	pid = fork();
	exit_if_fork_error(pid);
	if (pid > 0)
		wait(0);
	else
		run_cmd(pid, &arg, envp);
	return (0);
}
