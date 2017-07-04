#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/21 13:09:10 by rmalkevy          #+#    #+#              #
#    Updated: 2016/12/21 15:55:36 by yteslenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = 	figur.c \
        mass.c \
        solve.c \
        square.c \
        valid_part1.c \
        valid_part2.c \
        fillit.c

OBJ = $(SRC:.c=.o)

HEADER = libfill.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all