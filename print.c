/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:34:50 by salee2            #+#    #+#             */
/*   Updated: 2022/10/07 12:34:51 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	lack_of_args(void)
{
	ft_printf("It must take 4 or more arguments\n");
	return (-1);
}

void printEnvp(char **envp)
{
	printf("envp begin:===========================\n");
	int i=0;
	while(envp[i])
	{
		printf("%s\n", envp[i]);
		++i;
	}
	printf("envp end:===========================\n");
}