# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:35:32 by salee2            #+#    #+#              #
#    Updated: 2022/09/22 13:35:33 by salee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
BONUS		= pipex
PRINTFDIR	= ./ft_printf
PRINTFFILE	= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

MANDA_SRCS = \
	 dup.c \
	 env.c \
	 exit.c \
	 is.c \
	 main.c \
	 pipex.c \
	 redirection.c \
	 run.c \

BONUS_SRCS = \
	 dup_bonus.c\
	 env_bonus.c \
	 exit_bonus.c \
	 is_bonus.c \
	 main_bonus.c \
	 pipex_bonus.c \
	 redirection_bonus.c \
	 run_bonus.c \

MANDA_OBJS = $(addprefix mandatory/, $(MANDA_SRCS:c=o))
BONUS_OBJS = $(addprefix bonus/, $(BONUS_SRCS:c=o))

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(MANDA_OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTFDIR)/$(PRINTFFILE)

$(BONUS): $(BONUS_OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTFDIR)/$(PRINTFFILE)

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(PRINTFDIR) clean
	$(RM) $(MANDA_OBJS) $(BONUS_OBJS) $(MLXFILE) $(PRINTFFILE)

fclean: clean
	make -C $(PRINTFDIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
