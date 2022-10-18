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

#include "../pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;

	exit_if_invalid_arg(argc);
	pid = fork();
	if (pid < 0)
		exit_fork_error();
	else if (pid > 0)
		wait(0);
	else
		run_cmd(pid, argv, envp, 1);
	return (0);
}
