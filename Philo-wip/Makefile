#set a compiler, flags and name
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
NAME = philo

# path to source and object files, source and object files
SRC_PATH = src/
OBJ_PATH = obj/
SRC = error_handling.c \
existing.c \
init.c \
libft_utils.c \
observe.c \
philo_utils.c \
philo.c 
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCLUDE = -I ./includes/

# rules
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c includes/philo.h | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\n$(GREEN)$(NAME) is created!$(NC)"

clean:
	rm -rf $(OBJ_PATH)
	@echo "\n$(YELLOW)All the object files are removed.$(NC)"

fclean: clean
	rm -f $(NAME)
	@echo "\n$(RED)$(NAME) is removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re

# set colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m