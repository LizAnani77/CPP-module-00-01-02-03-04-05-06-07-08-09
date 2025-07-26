# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 17:33:40 by lanani-f          #+#    #+#             #
#    Updated: 2024/12/23 18:04:08 by lanani-f         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CLEAN_COLOR 		= 	\033[38;5;222m
REMOVE_COLOR 		= 	\033[38;5;166m
COMPILE_COLOR 		= 	\033[38;5;208m
BOX_COLOR 			= 	\033[38;5;202m
RESET 				= 	\033[0m

NAME 				= 	brain

CC 					= 	c++
CFLAGS 				= 	-Wall -Wextra -Werror -std=c++98

SRCS 				= 	main.cpp
OBJS 				= 	$(SRCS:.cpp=.o)

all: 				$(NAME)

$(NAME): $(OBJS)
	@echo "$(CLEAN_COLOR)╔════════════════════════════════════════════╗$(RESET)"
	@echo "$(CLEAN_COLOR)║             Compiling $(NAME)...             ║$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(CLEAN_COLOR)║    $(NAME) has been created successfully!    ║$(RESET)"
	@echo "$(CLEAN_COLOR)╚════════════════════════════════════════════╝$(RESET)"

%.o: %.cpp
	@echo "$(COMPILE_COLOR)▶ Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BOX_COLOR)🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(REMOVE_COLOR)🗑️  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re