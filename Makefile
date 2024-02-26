# set compiler and flags
CC = cc 
CFLAGS = -Wall -Wextra -Werror

# set source files and object files
SRC = $(shell ls *.c)
OBJ = $(SRC:.c=.o)

# set library name
NAME = libft.a

# to build the library
all: $(NAME)

# compile object files
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

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
