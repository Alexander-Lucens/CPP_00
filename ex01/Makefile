# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 14:21:13 by akuzmin           #+#    #+#              #
#    Updated: 2025/09/07 13:43:35 by akuzmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	phonebook

# **************************************************************************** #

SRCS		:=	phonebook.cpp
				
# **************************************************************************** #

CC			:=	c++

CFLAGS		:=	-Wall -Wextra -Werror -std=c++98

RM			:= rm -rf

OBJS		:= $(SRCS:.cpp=.o)

# **************************************************************************** #

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Creating program $(NAME)."

re: fclean all

clean:
	@$(RM) $(OBJS)
	@echo "Deleting object files for program $(NAME)."

fclean: clean
	@$(RM) $(NAME)
	@echo "Deleting library $(NAME)."

.PHONY: all re clean fclean make
