# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osfally <osfally@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 09:21:23 by osfally           #+#    #+#              #
#    Updated: 2019/02/09 15:17:36 by osfally          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#executable name
NAME		:=	fillit

SCR_PATH	:=	src
SRC_NAME	:=	main.c \
				reader.c \
				solver.c \

CPPFLAGS	:=	-Iincludes

OBJ_PATH	:=	obj
OBJ_NAME	:=	$(SRC_NAME:.c=.o)

SRC			:=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			:=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LDFLAGS		:=	-Llibft_shp/
LDLIBS		:=	-lft

CC			:=	clang

CFLAGS		:=	-Wall -Wextra -Werror
OFLAGS		:=	-ansi -pedantic
CFLAGS		+=	$(OFLAGS)

.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(CPPFLAGS)*.h

