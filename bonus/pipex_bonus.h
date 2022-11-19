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
# include "../ft_printf/ft_printf.h"

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

typedef struct s_arg
{
	char	**vec;
	int		idx;
	int		end;
	int		stdin_fd;
	int 	is_heredoc;
}	t_arg;

typedef int	t_bool;

void	redirect_w_pipe_to_stdout(int *pipe_fds);
void	redirect_r_pipe_to_stdin(int *pipe_fds);
char	**get_file_list(const char *name, char **env, char *file_name);
void	exit_fork_error(void);
void	exit_if_open_error(int fd, char *path);
void	exit_if_invalid_arg(int argc);
int		*make_pipe(void);
void	redirect_stdin_to_file(char *path);
void	redirect_stdout_to_file(char *path);
void	run_execve(char *argv, char **envp);
void	run_cmd(pid_t pid, t_arg *arg, char **envp);
void	io_redirection(t_arg *arg, char **envp);
char	*ft_get_env(const char *name, char **env);
char	*ft_mktemp(char **envp);
void	redirect_stdin_to_heredoc(char **envp, char *eof, int stdin);

#endif
