# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:53:47 by dpalmer           #+#    #+#              #
#    Updated: 2023/01/23 07:08:52 by dpalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		=	fdf

SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC			=	cc
CFLAGS		=	-O3 -Wall -Werror -Wextra

INC		 		= inc/
LIB_DIR			= lib/
LIBFT_DIR		= $(LIB)libft/
LIBFT			= $(LIB_DIR)libft.a
MINILIBX_DIR	= $(LIB)miniliblx/minilibx_macos/
MINILIBX		= $(MINILIBX_DIR)libmlx.a
MINILIBXCC		= -I mlx -L $(MINILIBX_DIR) -lmlx
HEADER 			= -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
OPENGL			= -framework OpenGL -framework AppKit

# Colors

C_RESET = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
B_MAGENTA = \033[1;35m
CYAN = \033[0;96m

#Sources

SRC_FILES	=	main			


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

###

all:		makelibs
			@$(MAKE) $(NAME)

makelibs:
			@$(MAKE) -C $(LIBFT_DIR)
			@$(MAKE) -C $(MINILIBX_DIR)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)		
			@echo "$(BLUE)$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)$(C_RESET)"
			@echo "$(B_MAGENTA)FdF compiled successfully...\n$(C_RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
			@mkdir -p $(OBJ_DIR)
			@echo "$(GREEN)Compiling: $(YELLOW)$<$(C_RESET)"
			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MINILIBX):
	@make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled...$(DEF_COLOR)"	

clean:
			@make clean -C $(LIBFT_DIR)
			@make clean -C $(MINILIBX_DIR)
			@rm -rf $(OBJ_DIR)
			@echo "$(BLUE)Object files DELETED$(C_RESET)"

fclean:		clean
			@rm -f $(NAME)
			@rm -f $(MINILIBX)
			@rm -f $(LIBFT)
			@echo "$(CYAN)Executable files DELETED$(C_RESET)"

re:			fclean all

.PHONY:		all clean fclean re makelibs