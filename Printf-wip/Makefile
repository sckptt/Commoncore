# set compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# set source files and object files (unfinished)
SRC = ft_printf.c \
ft_putchar_fd.c \
ft_puthexl_fd.c \
ft_puthexu_fd.c \
ft_putnbr_fd.c \
ft_putptr_fd.c \
ft_putstr_fd.c \
ft_putuns_fd.c \
ft_strchr.c \
main.c
OBJ = $(SRC:.c=.o)

# set library name
NAME = libftprintf.a

# to build the library
all: $(NAME)

# compile object files
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# dependencies
$(OBJ): libftprintf.h

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