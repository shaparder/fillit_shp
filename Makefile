# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osfally <osfally@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 09:21:23 by osfally           #+#    #+#              #
#    Updated: 2019/02/16 13:40:58 by osfally          ###   ########.fr        #
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

# uncomment next line to use sanitizer debug
CFLAGS		+=	$(DFLAGS)

# libraries
LIB_INC		:=	$(LIB_DIR)/includes
LIB_EXC		:=	$(LIB_DIR)/libft.a
LIB_OBJ		:=	$(LIB_DIR)/obj

.PHONY: all clean fclean re relib libclean libupdate libdl git cleanclean

all:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) >/dev/null || make
	@$(MAKE) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(LIB_INC) -I $(INC_DIR) -o $@ -c $<
	@echo "Objects created."

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB_EXC)
	@echo "Executable created."

# clean obj folder
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects cleaned."

# clean obj folder and executable
fclean: clean
	@rm -rf $(NAME)
	@echo "Executable cleaned."

# renew obj folder and executable
re: fclean all

# renew objects from libft
relib:
	@$(MAKE) -C $(LIB_DIR) re
	@$(MAKE) re
	@echo "Library objects refreshed."

# clean libft objects and lib file
libclean:
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo "Library obj and file cleaned."

# delete libft and re-download it
libupdate:
	@git rm -rf $(LIB_DIR)
	@$(MAKE) libdl

# download libft
libdl:
	@git clone https://github.com/shaparder/libft_shp.git libft
	@rm -rf libft/.git

# git add, push and commit
# usage: make git m=<your_commit_message>
git: cleanclean
	git add *
	git commit -m "$(m)"
	git push

# CLEANCLEANCLEAN
cleanclean: libclean fclean

infiniterun:
	sleep 24
	make all
	sleep 33
	make fclean
	@$(MAKE) infiniterun
