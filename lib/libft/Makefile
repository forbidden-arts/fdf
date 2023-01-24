# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 11:53:47 by dpalmer           #+#    #+#              #
#    Updated: 2023/01/24 13:16:52 by dpalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME		= libft.a
INCLUDE		= include/
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I
AR			= ar rcs


# Text Decoration

C_RESET = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
B_MAGENTA = \033[1;35m
CYAN = \033[0;96m


# Sources

SRC_FILES =	ft_atoi_base		\
			ft_atoi				\
			ft_bzero			\
			ft_isalnum			\
			ft_isalpha			\
			ft_isascii			\
			ft_isdigit			\
			ft_isprint			\
			ft_memchr			\
			ft_memcmp			\
			ft_memcpy			\
			ft_memmove			\
			ft_memset			\
			ft_strchr			\
			ft_strlcat			\
			ft_strlcpy			\
			ft_strlen			\
			ft_strncmp			\
			ft_strnstr			\
			ft_strrchr			\
			ft_tolower			\
			ft_toupper			\
			ft_calloc			\
			ft_strdup			\
			ft_substr			\
			ft_strjoin			\
			ft_strtrim			\
			ft_split			\
			ft_itoa				\
			ft_strmapi			\
			ft_striteri			\
			ft_putchar_fd		\
			ft_putstr_fd		\
			ft_putendl_fd		\
			ft_putnbr_fd		\
			ft_lstnew			\
			ft_lstadd_front		\
			ft_lstsize			\
			ft_lstlast			\
			ft_lstadd_back		\
			ft_lstdelone		\
			ft_lstclear			\
			ft_lstiter			\
			ft_lstmap			\
			ft_get_next_line	\
			ft_strrev			\
			ft_conv_utils		\
			ft_pf_printers		\
			ft_printf


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(B_MAGENTA)\n*-------------------------------*"
			@echo "|  LIBFT COMPILED SUCCESSFULLY  |"
			@echo "*-------------------------------*\n$(C_RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(GREEN)Compiling: $(YELLOW)$<$(C_RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@rm -rf $(OBJ_DIR)
			@echo "$(BLUE)OBJECT FILES DELETED$(C_RESET)"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(CYAN)LIBFT ARCHIVE DELETED$(C_RESET)"

re:			fclean all

.PHONY:		all clean fclean re
