# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 18:09:08 by vkinsfat          #+#    #+#              #
#    Updated: 2024/12/26 18:22:56 by vkinsfat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#set variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = zombie
SRC = Zombie.cpp \
newZombie.cpp \
randomChump.cpp \
main.cpp
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