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
PRINTFDIR	= ./ft_printf
PRINTFFILE	= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS = \
	 main.c \

OBJS = $(SRCS:c=o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTFDIR)/$(PRINTFFILE)

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(PRINTFDIR) clean
	$(RM) $(OBJS) $(MLXFILE) $(PRINTFFILE)

fclean: clean
	make -C $(PRINTFDIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
