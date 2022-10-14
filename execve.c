/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:49:49 by salee2            #+#    #+#             */
/*   Updated: 2022/10/14 18:49:50 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_execve(char* argv, char **envp)
{
	char **arg_vec = ft_split(argv, ' ');
	char **file_list = get_file_list("PATH", envp, arg_vec[0]);
	int i = -1;
	while (file_list[++i])
	{
		if (access(file_list[i], F_OK) == 0)
		{
			if (execve(file_list[i], arg_vec, envp) == -1)
			{
				perror("Could not execute execve");
				exit(EXIT_FAILURE);
			}
		}
	}
	return ;
}
