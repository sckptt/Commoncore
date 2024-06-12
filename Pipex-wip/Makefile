# set a compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# path to source and object files, source and object files
SRC_PATH = src/
OBJ_PATH = obj/
SRC = pipex.c \
utils.c
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCLUDE = -I ./includes/

# set the name
NAME = pipex
LIBNAME = libft.a
LIBFT_DIR = Libft/

# rules
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c includes/pipex.h | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBNAME)
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