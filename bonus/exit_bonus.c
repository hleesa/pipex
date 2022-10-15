/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:58:26 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 16:58:28 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exit_fork_error(void)
{
	perror("fork()");
	exit(EXIT_FAILURE);
}

void	exit_if_invalid_arg(int argc)
{
	if (!is_right_args(argc))
	{
		perror("invalid arg");
		exit(EXIT_FAILURE);
	}
	return ;
}
