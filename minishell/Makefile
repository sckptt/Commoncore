# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 15:31:13 by akulikov          #+#    #+#              #
#    Updated: 2024/12/05 18:16:10 by vkinsfat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# set a compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# path to source and object files, source and object files
SRC_PATH = src/
OBJ_PATH = obj/
SRC = built-in/ft_cd.c \
built-in/ft_echo.c \
built-in/ft_env.c \
built-in/ft_exit.c \
built-in/ft_export.c \
built-in/ft_pwd.c \
built-in/ft_unset.c \
exec/children.c \
exec/execution1.c \
exec/execution2.c \
exec/execution3.c \
exec/file_manager1.c \
exec/file_manager2.c \
exec/file_manager3.c \
parsing/expand_utils.c \
parsing/expand.c \
parsing/lexer_utils1.c \
parsing/lexer_utils2.c \
parsing/lexer_utils3.c \
parsing/lexer_utils4.c \
parsing/lexer.c \
parsing/pre_parser_utils1.c \
parsing/pre_parser_utils2.c \
parsing/pre_parser_utils3.c \
parsing/pre_parser.c \
parsing/quotes_handling.c \
parsing/syntax_check.c \
utils/built-in_utils1.c \
utils/built-in_utils2.c \
utils/children_utils.c \
utils/children_utils2.c \
utils/env_utils.c \
utils/envp_array_utils.c \
utils/execution_utils.c \
utils/free_utils1.c \
utils/free_utils2.c \
utils/get_next_line_utils.c \
utils/get_next_line.c \
utils/print_utils.c \
utils/signals.c \
env_init.c \
init.c \
main.c
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCLUDE = -I ./include/ -I $(LIBFT_DIR)/include/

# set the name
NAME = minishell
LIBNAME = libft.a
LIBFT_DIR = libft/

# rules
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c include/minishell.h | $(OBJ_PATH)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)  -L$(LIBFT_DIR) -lft -lreadline
	@echo "\n$(GREEN)$(NAME) is created!$(NC)"

clean:
	rm -rf $(OBJ_PATH)
	@echo "\n$(YELLOW)All the object files are removed.$(NC)"

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(LIBNAME)
	@echo "\n$(RED)$(NAME) is removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re

# set colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m
