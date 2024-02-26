# set compiler and flags
CC = cc 
CFLAGS = -Wall -Wextra -Werror

# set source files and object files
SRC = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c
OBJ = $(SRC:.c=.o)

# set library name
NAME = libft.a

# to build the library
all: $(NAME)

# compile object files
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# dependencies
$(OBJ): libft.h

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