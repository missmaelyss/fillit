# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 15:51:10 by marnaud           #+#    #+#              #
#    Updated: 2016/12/07 16:42:10 by marnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = create_tab.c \
	  erase_piece.c \
	  initialise_cursor.c \
	  main.c \
	  save_piece.c \
	  valid_file.c \
	  valid_piece.c \
	  write_piece.c \
	  write_tab.c \
	  ft_putstr.c \
	  ft_putchar.c \

OBJ = $(SRC:%.c=%.o)

all:
	gcc -Wall -Werror -Wextra -c $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
