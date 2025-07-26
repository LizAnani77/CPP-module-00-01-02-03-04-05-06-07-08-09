# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 20:33:40 by lanani-f          #+#    #+#             #
#    Updated: 2024/12/29 20:34:08 by lanani-f         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CLEAN_COLOR 	= 	\033[38;5;55m
REMOVE_COLOR 	= 	\033[38;5;56m
COMPILE_COLOR 	= 	\033[38;5;99m
BOX_COLOR 		= 	\033[38;5;141m
RESET 			= 	\033[0m

NAME 			= 	zombie

CC 				= 	c++
CFLAGS 			= 	-Wall -Wextra -Werror -std=c++98

SRCS 			= 	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS 			= 	$(SRCS:.cpp=.o)

all: 			$(NAME)

$(NAME): $(OBJS)
	@echo "$(BOX_COLOR)╔════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOX_COLOR)║        Compiling $(NAME)...                 ║$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(BOX_COLOR)║  $(NAME) has been created successfully!     ║$(RESET)"
	@echo "$(BOX_COLOR)╚════════════════════════════════════════════╝$(RESET)"

%.o: %.cpp
	@echo "$(COMPILE_COLOR)▶ Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(CLEAN_COLOR)🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(REMOVE_COLOR)🗑️  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re