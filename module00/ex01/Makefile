# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 01:43:40 by lizzieanani       #+#    #+#              #
#    Updated: 2025/01/04 00:30:19 by lizzieanani      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAN_COLOR     =   \033[38;5;23m
REMOVE_COLOR    =   \033[38;5;36m
COMPILE_COLOR   =   \033[38;5;43m
BOX_COLOR       =   \033[38;5;122m
RESET			=	\033[0m

NAME 			= 	phonebook
CC 				= 	c++
CFLAGS 			= 	-Wall -Wextra -Werror -std=c++98

SRCS 			= 	main.cpp PhoneBook.cpp Contact.cpp
OBJS 			= 	$(SRCS:.cpp=.o)

all: 			$(NAME)

$(NAME): 		$(OBJS)
	@echo "$(BOX_COLOR)╔═══════════════════════════════════════════╗$(RESET)"
	@echo "$(BOX_COLOR)║         Compiling $(NAME)...            ║$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(BOX_COLOR)║  $(NAME) has been created successfully! ║$(RESET)"
	@echo "$(BOX_COLOR)╚═══════════════════════════════════════════╝$(RESET)"

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
