/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:58:26 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 16:58:28 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_if_fork_error(pid_t pid)
{
	if (pid < 0)
	{
		perror("fork()");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	exit_if_open_error(int fd, char *path)
{
	if (fd == -1)
	{
		ft_printf("pipex: %s: ", path);
		perror("");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	exit_if_invalid_arg(int argc)
{
	if (argc < 5)
	{
		perror("invalid arg");
		exit(EXIT_FAILURE);
	}
	return ;
}
