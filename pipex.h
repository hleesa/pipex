/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:23:55 by salee2            #+#    #+#             */
/*   Updated: 2022/09/29 12:23:57 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ft_printf/ft_printf.h"

enum e_pipe_fds
{
	READER_FD = 0,
	WRITER_FD = 1,
};

enum e_bool
{
	FALSE,
	TRUE
};

typedef int t_bool;

typedef struct s_arg_info
{
	char *infile;
	char **cmd;
	char *outfile;
}	t_arg_info;

char**	get_file_list(const char *name, char**env, char* file_name);






#include <string.h>

#endif //PIPEX_H
