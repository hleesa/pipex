/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:58:52 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 16:58:54 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	input_redirection(char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (fd == -1)
	{
		perror("open()");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}

void	output_redirection(char *path)
{
	const int	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		perror("open()");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}

void	io_redirection(t_arg *arg)
{
	if (arg->idx == 2)
		input_redirection(arg->vec[1]);
	if (arg->idx + 2 == arg->end)
		output_redirection(arg->vec[arg->end - 1]);
	return ;
}
