# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: username <username@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 10:00:00 by username          #+#    #+#             #
#    Updated: 2024/12/30 10:00:00 by username         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAN_COLOR     =   \033[38;5;214m
REMOVE_COLOR    =   \033[38;5;220m
COMPILE_COLOR   =   \033[38;5;226m
BOX_COLOR       =   \033[38;5;230m
RESET           =   \033[0m

NAME            =   bsp

CC              =   c++
CFLAGS          =   -Wall -Wextra -Werror -std=c++98

SRCS            =   main.cpp \
                    Fixed.cpp \
                    Point.cpp \
                    bsp.cpp

OBJS            =   $(SRCS:.cpp=.o)

all:                $(NAME)

$(NAME): $(OBJS)
	@echo "$(BOX_COLOR)╔════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOX_COLOR)║              Compiling $(NAME)...              ║$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(BOX_COLOR)║      $(NAME) has been created successfully!    ║$(RESET)"
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