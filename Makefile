# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edramire <edramire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 14:00:28 by edramire          #+#    #+#              #
#    Updated: 2020/03/04 17:05:39 by edramire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(OS), Windows_NT)
	UNAME := Windows
else
	UNAME := $(shell uname -s)
endif

ifeq ($(UNAME), Linux)
	OPENGL := -lmlx -lXext -lX11
else
	OPENGL := -framework OpenGL -framework AppKit -L /usr/local/lib -lmlx
endif

NAME := game
FT := libft

FLAGS := -Wall -Werror -Wextra
LIBS := -I minilibx
CC := gcc $(FLAGS) $(LIBS)

SRC := \
	game_draw.c			\
	game_init.c			\
	game_loop.c			\

ifeq ($(UNAME), Linux)
	SRC := $(SRC) strlcpy.c
endif

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(NAME).c $(OBJS) -lm $(OPENGL)

debug:
	$(CC) -o $(NAME) $(NAME).c $(SRC) -lm -g $(OPENGL)

.PHONY: all bonus clean fclean re

clean:
	rm -rf *.out
	rm -rf *.dSYM
	rm -rf *.o 
	rm -rf *.bmp

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $< -I $(FT)
