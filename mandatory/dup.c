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
	close(pipe_fds[READER_FD]);
	if (dup2(pipe_fds[WRITER_FD], STDOUT_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(pipe_fds[WRITER_FD]);
	return ;
}

void	dup_read_fd(int *pipe_fds)
{
	close(pipe_fds[WRITER_FD]);
	if (dup2(pipe_fds[READER_FD], STDIN_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(pipe_fds[READER_FD]);
	return ;
}
