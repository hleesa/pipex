/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_pipe_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:53:30 by salee2            #+#    #+#             */
/*   Updated: 2022/11/19 19:53:40 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	redirect_w_pipe_to_stdout(int *pipe_fds)
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

void	redirect_r_pipe_to_stdin(int *pipe_fds)
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
