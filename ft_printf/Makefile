# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 13:40:31 by salee2            #+#    #+#              #
#    Updated: 2022/08/06 13:40:33 by salee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFTDIR	= ./libft
LIBFTFILE	= libft.a
GNLDIR		= ./get_next_line

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS = \
	ft_printf.c \
	ft_csdiu.c \
	ft_pxp.c \
	ft_utoa.c \
	$(GNLDIR)/get_next_line.c \
	$(GNLDIR)/get_next_line_utils.c \
	$(GNLDIR)/get_next_line_bonus.c \
	$(GNLDIR)/get_next_line_utils_bonus.c \

OBJS_M = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_M)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $@
	$(AR) $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(OBJS_M)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
