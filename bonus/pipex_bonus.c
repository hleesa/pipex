/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:58:48 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 16:58:50 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	*make_pipe(void)
{
	int	*pipe_fds;

	pipe_fds = malloc(sizeof(int) * 2);
	if (pipe_fds == NULL)
	{
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fds) == -1)
	{
		perror("pipe()");
		exit(EXIT_FAILURE);
	}
	return (pipe_fds);
}
