# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecloete <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/17 12:25:26 by ecloete           #+#    #+#              #
#    Updated: 2017/07/21 12:18:08 by ecloete          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c \
	  draw.c \
	  keypress.c \
	  render.c \
	  read.c \

OBJ = ${SRC:c=o}

FLAGS = -lmlx -framework Opengl -framework Appkit -Werror -Wextra -Wall

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):
		gcc -c $(SRC)
		gcc -o $(NAME) $(OBJ) $(LIBFT) $(FLAGS)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
