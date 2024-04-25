# set compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# set source files and object files (unfinished)
SRC_PATH = src/
OBJ_PATH = obj/
SRC = ft_printf.c \
ft_putchar.c \
ft_puthexl.c \
ft_puthexu.c \
ft_putnbr.c \
ft_putptr.c \
ft_putstr.c \
ft_putuns.c \
ft_strchr.c \
ft_strlen.c
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCLUDE = -I ./includes/

# set library name
NAME = libftprintf.a

# to build the library
all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c includes/ft_printf.h | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 
	@echo "\n$(GREEN)$(NAME) is created!$(NC)"

clean:
	rm -rf $(OBJ_PATH)
	@echo "\n$(YELLOW)All the object files are removed.$(NC)"

fclean: clean
	rm -f $(NAME)
	@echo "\n$(RED)$(NAME) is removed.$(NC)"

re: fclean all

# set colors
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m

# phony targets
.PHONY: all clean fclean re