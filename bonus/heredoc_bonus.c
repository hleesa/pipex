/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:40:15 by salee2            #+#    #+#             */
/*   Updated: 2022/10/27 15:40:15 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	redirect_stdin_to_heredoc(char **envp, char *eof, int stdin_fd)
{
	int		fd;
	char	*path;
	char	*input;

	path = ft_mktemp(envp);
	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	exit_if_open_error(fd, path);
	while (TRUE)
	{
		input = get_next_line(stdin_fd);
		if (input == NULL)
			break ;
		if (ft_strncmp(input, eof, ft_strlen(eof)) == 0)
		{
			free(input);
			break ;
		}
		else
		{
			write(fd, input, ft_strlen(input));
			free(input);
		}
	}
	redirect_stdin_to_file(path);
	return ;
}
