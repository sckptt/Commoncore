# set a compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# path to source and object files, source and object files
SRC_PATH = src/
OBJ_PATH = obj/
SRC = error_handling.c \
error_handling2.c \
free_and_go_home.c \
game_start.c \
get_next_line.c \
get_next_line_utils.c \
graphic_utils.c \
hook_events.c \
map_utils.c \
moves.c \
so_long.c
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCLUDE = -I ./includes/

# set the name
NAME = so_long
LIBFT_DIR = Libft/
LIBMLX = minilibx-linux/libmlx.a
LIBMLX_LDLIBS = $(LIBMLX) -lXext -lX11 -lm

# rules
all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c includes/so_long.h | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a $(LIBMLX_LDLIBS)
	@echo "\n$(GREEN)$(NAME) is created!$(NC)"

clean:
	rm -rf $(OBJ_PATH)
	@echo "\n$(YELLOW)All the object files are removed.$(NC)"

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) libft.a
	@echo "\n$(RED)$(NAME) is removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re

# set colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m