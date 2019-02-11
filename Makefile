# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osfally <osfally@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 09:21:23 by osfally           #+#    #+#              #
#    Updated: 2019/02/10 16:13:07 by osfally          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# executable name
NAME	:= fillit

# directories
SRC_DIR	:= ./src
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./libft

# src / obj files
SRC		:= main.c

OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c99
DEBUG	:=	-fsanitize=address -fsanitize=undefined -g
# CFLAGS	+= $(OFLAGS)
OFLAGS	:= -pipe -flto

# libraries
L_FT	:= $(LIB_DIR)

include $(L_FT)/libft.mk

.PHONY: all clean fclean re

all:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(L_FT) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "Objects and executable cleaned."

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(L_FT) re --no-print-directory
	@$(MAKE) re --no-print-directory
