# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:53:47 by dpalmer           #+#    #+#              #
#    Updated: 2023/01/23 11:04:19 by dpalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR	 	=	include/
LIBFT		=	lib/libft
LIBFT_A		=	$(LIBFT)/libft.a

CC			=	cc
CFLAGS		=	-O3 -Wall -Werror -Wextra
MLXFLAGS	=	-framework OpenGL -framework AppKit

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

###

all:		makelibs
			@$(MAKE) $(NAME)

makelibs:
			@$(MAKE) -C $(LIBFT)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L. $(LIBFT_A) -L. -lmlx $(MLXFLAGS)
			@echo "$(B_MAGENTA)\n$(NAME) compiled successfully...\n$(C_RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(GREEN)Compiling: $(BLUE)$<$(C_RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@make clean -C $(LIBFT)
			@rm -rf $(OBJ_DIR)
			@echo "$(BLUE)MINILIB OBJECTS DELETED$(C_RESET)"


fclean:		clean
			@rm -f $(NAME)
			@rm -f $(LIBFT_A)
			@echo "$(CYAN)EXECUTABLE DELETED$(C_RESET)"

re:			fclean all

.PHONY:		all clean fclean re makelibs

# # Variables

# NAME		=	fdf

# SRC_DIR		=	src/
# OBJ_DIR		=	obj/
# INC_DIR	 	=	include/

# CC			=	cc
# CFLAGS		=	-O3 -Wall -Werror -Wextra


# LIB				= lib/
# LIBFT_DIR		= $(LIB)libft/
# LIBFT			= $(LIBFT_DIR)libft.a
# MINILIBX_DIR	= $(LIB)minilibx_macos/
# MINILIBX		= $(MINILIBX_DIR)libmlx.a
# MINILIBXCC		= -L. -lmlx
# HEADER 			= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
# OPENGL			= -framework OpenGL -framework AppKit

# # Colors

# C_RESET = \033[0;39m
# GREEN = \033[0;92m
# YELLOW = \033[0;93m
# BLUE = \033[0;94m
# B_MAGENTA = \033[1;35m
# CYAN = \033[0;96m

# #Sources

# SRC_FILES	=	main


# SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
# OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# ###

# all:		makelibs
# 			@$(MAKE) $(NAME)

# makelibs:
# 			@$(MAKE) -C $(LIBFT_DIR)

# $(NAME):	$(OBJ)
# 			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(OPENGL) -o $(NAME)
# 			@$(BLUE)$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)$(C_RESET)"
# 			@echo "$(B_MAGENTA)FdF compiled successfully...\n$(C_RESET)"

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
# 			@mkdir -p $(OBJ_DIR)
# 			@echo "$(GREEN)Compiling: $(YELLOW)$<$(C_RESET)"
# 			@$(CC) $(CFLAGS) -MMD -c $< -o $@

# $(LIBFT):
# 	@make -C $(LIBFT_DIR)

# # $(MINILIBX):
# # 	@make -C $(MINILIBX_DIR)
# # 	@echo "$(GREEN)Minilibx compiled...$(C_RESET)"

# clean:
# 			@make clean -C $(LIBFT_DIR)
# 			# @make clean -C $(MINILIBX_DIR)
# 			@rm -rf $(OBJ_DIR)
# 			@echo "$(BLUE)MINILIB OBJECTS DELETED$(C_RESET)"

# fclean:		clean
# 			@rm -f $(NAME)
# 			# @rm -f $(MINILIBX)
# 			@rm -f $(LIBFT)
# 			@echo "$(CYAN)EXECUTABLE DELETED$(C_RESET)"

# re:			fclean all

# .PHONY:		all clean fclean re makelibs
