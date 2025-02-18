# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 17:57:06 by vitakinsfat       #+#    #+#              #
#    Updated: 2025/02/11 13:34:44 by vitakinsfat      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#set variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fixed
SRC = main.cpp \
Fixed.cpp
OBJ = $(SRC:.cpp=.o)
INCLUDE = -I.

#set rules
all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
