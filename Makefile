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

MANDA_SRCS = \
	 dup \
	 env \
	 exit \
	 is \
	 main \
	 pipex \
	 redirection \
	 run \

BONUS_SRCS = \
	 dup \
     env \
     exit \
     heredoc \
     is \
     main \
     mktemp \
     pipex \
     redirection \
     run \

MANDA_FILE = $(addsuffix .c, $(addprefix mandatory/, $(MANDA_SRCS:.c=.o)))
BONUS_FILE = $(addsuffix _bonus.c, $(addprefix bonus/, $(BONUS_SRCS:.c=.o)))

MANDA_OBJS = $(MANDA_FILE:c=o)
BONUS_OBJS = $(BONUS_FILE:c=o)

ifdef WITH_BONUS
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MANDA_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTFDIR)/$(PRINTFFILE)

bonus:
	make WITH_BONUS=1 all

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(PRINTFDIR) clean
	$(RM) $(MANDA_OBJS) $(BONUS_OBJS) $(PRINTFFILE)

fclean: clean
	make -C $(PRINTFDIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
