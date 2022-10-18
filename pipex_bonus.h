/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:55:49 by salee2            #+#    #+#             */
/*   Updated: 2022/10/15 16:56:00 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "ft_printf/ft_printf.h"

enum e_pipe_fds
{
	READ_FD = 0,
	WRITE_FD = 1,
};

enum e_bool
{
	FALSE,
	TRUE
};

typedef int	t_bool;

void	dup_write_fd(int *pipe_fds);
void	dup_read_fd(int *pipe_fds);
char	**get_file_list(const char *name, char **env, char *file_name);
void	exit_fork_error(void);
void	exit_if_invalid_arg(int argc);
t_bool	is_right_args(int argc);
int		*make_pipe(void);
void	input_redirection(char *path);
void	output_redirection(char *path);
void	run_execve(char *argv, char **envp);
void	run_cmd(pid_t pid, char **argv, char **envp, int arg_idx, int arg_end);

#endif
