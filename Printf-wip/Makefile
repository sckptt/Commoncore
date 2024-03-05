# set compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# set source files and object files (unfinished)
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

# set library name
NAME = libftprintf.a

# to build the library
all: $(NAME)

# compile object files
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# dependencies
$(OBJ): ft_printf.h

# create library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# remove object files
clean:
	rm -f $(OBJ)

# remove object files and library
fclean:
	rm -f $(OBJ) $(NAME)

# remove object files, library and recompile
re: fclean all

# phony targets
.PHONY: all clean fclean re