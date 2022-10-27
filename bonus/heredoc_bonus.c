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

void	input_redirection_heredoc(char **envp, char *eof)
{
	const char	*path = ft_mktemp(envp);
	const int	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (fd == -1)
	{
		ft_printf("pipex: %s: ", path);
		perror("");
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

void	wrtie_heredoc(char **envp, char *eof)
{
	input_redirection_heredoc(envp, eof);
	while (TRUE)
	{
		char *input = get_next_line(STDIN_FILENO);
		if (input == NULL)
			return;
		if (ft_strcmp(input, eof) == 0)
		{
			free(input);
			return;
		} else
		{
			write(STDIN_FILENO, input, ft_strlen(input));
			free(input);
		}
	}
}