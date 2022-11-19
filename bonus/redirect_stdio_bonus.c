/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdio_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:53:49 by salee2            #+#    #+#             */
/*   Updated: 2022/11/19 19:54:02 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	redirect_stdout_to_file_append(char *path)
{
	const int	fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644);

	exit_if_open_error(fd, path);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	close(fd);
	return ;
}

void	redirect_stdio(t_arg *arg, char **envp)
{
	if (arg->is_heredoc)
	{
		if (arg->idx == 3)
			redirect_stdin_to_heredoc(envp, arg->vec[2], arg->stdin_fd);
		else if (arg->idx + 2 == arg->end)
			redirect_stdout_to_file_append(arg->vec[arg->end - 1]);
	}
	else
	{
		if (arg->idx == 2)
			redirect_stdin_to_file(arg->vec[1]);
		else if (arg->idx + 2 == arg->end)
			redirect_stdout_to_file(arg->vec[arg->end - 1]);
	}
	return ;
}
