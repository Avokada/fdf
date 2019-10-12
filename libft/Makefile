# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thaley <thaley@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 13:53:44 by cdenys-a          #+#    #+#              #
#    Updated: 2019/07/05 15:47:47 by thaley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = $(wildcard *.c)
OBJS = *.o

all: ${NAME}

${NAME}:
	gcc -g -Wall -Wextra -Werror -c ${SRCS} -I.
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

so:
	gcc -shared -o libft.so -fPIC ft_*.c -I.

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

norm:
	norminette ft_* libft.h
