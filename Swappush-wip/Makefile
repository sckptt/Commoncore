# set a compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# path to source and object files, source and object files
SRC_PATH = src/
OBJ_PATH = obj/
SRC = big_sort.c \
error_check.c \
free_and_go_home.c \
push_swap.c \
push.c \
reverse_rotate.c \
rotate.c \
swap.c \
small_sort.c \
sort_utils.c \
stack_utils.c \
utils1.c \
utils2.c
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCLUDE = -I ./includes/

# set the name
NAME = push_swap
PRINTF_DIR = Printf/

# rules
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c includes/push_swap.h | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_DIR)/libftprintf.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libftprintf.a
	@echo "\n$(GREEN)$(NAME) is created!$(NC)"

clean:
	rm -rf $(OBJ_PATH)
	@echo "\n$(YELLOW)All the object files are removed.$(NC)"

fclean: clean
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME) libftprintf.a
	@echo "\n$(RED)$(NAME) is removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re

# set colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m