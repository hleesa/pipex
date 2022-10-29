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

void	input_redirection_heredoc(char **envp, char *eof, int stdin_fd)
{
	const char	*path = ft_mktemp(envp);
	const int	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);

	ft_printf("eof:%s\n", eof);
	if (fd == -1)
	{
		ft_printf("pipex: %s: ", path);
		perror("");
		exit(EXIT_FAILURE);
	}
	while (TRUE)
	{
		char *input = get_next_line(stdin_fd);
		if (input == NULL)
			break;
		if (ft_strncmp(input, eof, ft_strlen(eof)) == 0)
		{
			free(input);
			break ;
		} else
		{
			write(fd, input, ft_strlen(input));
			free(input);
		}
	}
	dup2(fd, STDIN_FILENO);
	unlink(path);
	close(fd);
	return ;
}
