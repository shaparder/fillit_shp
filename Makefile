# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osfally <osfally@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 09:21:23 by osfally           #+#    #+#              #
#    Updated: 2019/02/13 22:45:30 by osfally          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# executable name
NAME		:= fillit

# directories
SRC_DIR		:=	./src
INC_DIR		:=	./includes
OBJ_DIR		:=	./obj
LIB_DIR		:=	./libft

# src / obj files
SRC			:=	main.c

OBJ			:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -pedantic -std=c99
DFLAGS		:=	-fsanitize=address -g
# OFLAGS		:=	-pipe -flto
# CFLAGS		+= $(OFLAGS)

# uncomment next line to use sanitizer debug
#CFLAGS		+=	$(DFLAGS)

# libraries
LIB_INC		:=	$(LIB_DIR)/includes
LIB_EXC		:=	$(LIB_DIR)/libft.a
LIB_OBJ		:=	$(LIB_DIR)/obj

.PHONY: all clean fclean re

all:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) >/dev/null || make
	@$(MAKE) $(NAME)
	@echo "Executable created."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB_EXC)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable cleaned."

re: fclean all

relib:
	@$(MAKE) -C $(LIB_DIR) re
	@$(MAKE) re

libclean:
	@rm -rf $(LIB_OBJ)
	@rm -rf $(LIB_EXC)
	@echo "Library obj and file cleaned."

libupdate:
	@git rm -rf $(LIB_DIR)
	@$(MAKE) libdl

libdl:
	@git clone https://github.com/shaparder/libft_shp.git libft
	@rm -rf libft/.git
	@git add *
	@git commit -m "$(m)"
	@git push

gitt:
	git add *
	git commit -m "$(m)"
	git push

cleanclean: libclean fclean
