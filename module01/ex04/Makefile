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

# Couleurs pour chaque type de message dans l'ordre d'apparition
CLEAN_COLOR 	= 	\033[38;5;76m
REMOVE_COLOR 	= 	\033[38;5;77m
COMPILE_COLOR 	= 	\033[38;5;78m
BOX_COLOR		= 	\033[38;5;79m
RESET 			= 	\033[0m

NAME 			= 	replace

CC 				= 	c++
CFLAGS 			= 	-Wall -Wextra -Werror -std=c++98

SRCS 			= 	main.cpp FileReplacer.cpp
OBJS 			= 	$(SRCS:.cpp=.o)

all: 			$(NAME)

$(NAME): $(OBJS)
	@echo "$(BOX_COLOR)╔════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOX_COLOR)║$(RESET)            $(BOX_COLOR)Compiling $(NAME)...            $(BOX_COLOR)║$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)     
	@echo "$(BOX_COLOR)║$(RESET)   $(BOX_COLOR)$(NAME) has been created successfully!   $(BOX_COLOR)║$(RESET)"
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