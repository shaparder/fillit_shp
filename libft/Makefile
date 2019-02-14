# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osfally <osfally@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 10:35:14 by osfally           #+#    #+#              #
#    Updated: 2019/02/10 17:53:01 by osfally          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# executable name
NAME		:=	libft.a

# directories
SRC_DIR		:=	./src
OBJ_DIR		:=	./obj
INC_DIR		:=	./includes

RAW_SRC		:= $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
RAW_DIRS	:= $(shell find $(SRC_DIR) -type d -mindepth 1)
SRC_DIRS 	= $(RAW_DIRS:./src/%=%)
SRC			= $(RAW_SRC:./src/%=%)
OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))


# compilateur / flags
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/,$(SRC_DIRS))

# create obj folder and object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $<

# create lib file and an index
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects cleaned."

fclean:	clean
	@rm -rf $(NAME)
	@echo "Executable cleaned."

re: fclean all
