# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iletimil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 23:45:11 by iletimil          #+#    #+#              #
#    Updated: 2018/08/13 01:28:45 by iletimil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
HEADER = fdf.h
FLAGS = -Wall -Werror -Wextra
CC = gcc
SRC = ft_read.c \
	  ft_scopedy.c \
	  get_next_line.c \
	  
all:    $(NAME)

$(NAME):
			@$(CC) -c $(SRC) $(FLAGS)
			@ar rcs $(NAME) *.o
			@ranlib $(NAME)
			@$(CC) -o fdf ft_draw.c fdf.a -lmlx -framework OpenGL -framework AppKit -L ./libft -lft
			@echo "Edo Tensei"
%.o:	$(HEADER)
clean:
			@-rm -f *.o

fclean:		clean
			@-rm -f *.a
			@-rm fdf
			@echo "*Thanos snaps his fingers"

re:			fclean all

