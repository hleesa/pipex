/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdio.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:43:22 by salee2            #+#    #+#             */
/*   Updated: 2022/11/19 20:43:22 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_stdin_to_file(char *path)
{
	const int	fd = open(path, O_RDONLY);

	exit_if_open_error(fd, path);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}

void	redirect_stdout_to_file(char *path)
{
	const int	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);

	exit_if_open_error(fd, path);
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
		redirect_stdin_to_file(arg->vec[1]);
	else if (arg->idx + 2 == arg->end)
		redirect_stdout_to_file(arg->vec[arg->end - 1]);
	return ;
}
