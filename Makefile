# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:53:47 by dpalmer           #+#    #+#              #
#    Updated: 2023/01/19 11:43:40 by dpalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		=	fdf
NAMELIB		=	fdf.a
INCLUDE		=	-I include
LIBFT		=	libft
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar rcs

# Colors

C_RESET = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
B_MAGENTA = \033[1;35m
CYAN = \033[0;96m

#Sources

SRC_FILES	=	fdf


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@mv $(LIBFT)/libft.a ./libft.a
			@mv libft.a $(NAMELIB)
			@$(AR) $(NAMELIB) $(OBJ)
			@$(CC) $(CFLAGS) $(INCLUDE) $(NAMELIB) -o fdf
			@echo "$(B_MAGENTA)FDF COMPILED SUCCESSFULLY\n$(C_RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(GREEN)Compiling: $(YELLOW)$<$(C_RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@rm -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)OBJECT FILES DELETED$(C_RESET)"

fclean:		clean
			@rm -f $(NAME) $(NAMELIB)
			@echo "$(CYAN)EXECUTABLE FILES DELETED$(C_RESET)"

re:			fclean all
