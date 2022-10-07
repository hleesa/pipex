/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:13:50 by salee2            #+#    #+#             */
/*   Updated: 2022/10/06 16:13:51 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	is_right_args(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		++i;
	return (i > 3);
}

int get_args_end(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		++i;
	return (i);\
}

void	set_arg_info(char **argv, t_arg_info *arg_info)
{
	int i;
	const int arg_end = get_args_end(argv);

	if (!is_right_args(argv))
		exit(lack_of_args());
	arg_info->infile = argv[0];
	i = 0;
	while(argv[++i])
	{

	}
}