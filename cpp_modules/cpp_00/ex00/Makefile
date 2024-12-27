# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 18:08:37 by vkinsfat          #+#    #+#              #
#    Updated: 2024/12/26 18:08:38 by vkinsfat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#set variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

#set rules
all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
