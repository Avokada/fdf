# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/06 18:57:03 by thaley            #+#    #+#              #
#    Updated: 2019/10/16 14:04:07 by aaeron-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -g #-Wall -Wextra -Werror

SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = -I libft -I include
LIBS = -L libft -lft -lmlx -framework OpenGL -framework AppKit

SRCS = main.c exit.c key_press.c rotate.c draw.c\
	read_file.c write_line.c graphics_test.c point.c\
	put_color.c map_type.c read_colors.c make_map.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR):
	mkdir obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
		/bin/rm -f $(OBJS) $(wildcard *.gch)
		make clean -C libft/

fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C libft/

re: fclean all
