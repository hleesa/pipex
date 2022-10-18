/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:52:10 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 15:52:11 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	dup_write_fd(int *pipe_fds)
{
	close(pipe_fds[READ_FD]);
	if (dup2(pipe_fds[WRITE_FD], STDOUT_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(pipe_fds[WRITE_FD]);
	return ;
}

void	dup_read_fd(int *pipe_fds)
{
	close(pipe_fds[WRITE_FD]);
	if (dup2(pipe_fds[READ_FD], STDIN_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(pipe_fds[READ_FD]);
	return ;
}
