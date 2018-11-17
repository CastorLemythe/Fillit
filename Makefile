# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kehuang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 10:17:59 by kehuang           #+#    #+#              #
#    Updated: 2017/12/09 11:21:34 by kehuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRCS = main.c				\
	   ft_resolve_tetris.c	\
	   ft_check_possible.c	\
	   ft_init_and_clean.c	\
	   ft_sample_valid.c	\
	   ft_put_solution.c	\
	   ft_putchar.c			\
	   ft_putstr.c			\
	   ft_memset.c			\
	   ft_isalpha.c
OBJS = main.o				\
	   ft_resolve_tetris.o	\
	   ft_check_possible.o	\
	   ft_init_and_clean.o	\
	   ft_sample_valid.o	\
	   ft_put_solution.o	\
	   ft_putchar.o			\
	   ft_putstr.o			\
	   ft_memset.o			\
	   ft_isalpha.o

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS)
	gcc -o $(NAME) $(FLAGS) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
