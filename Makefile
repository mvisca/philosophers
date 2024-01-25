# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:22:41 by mvisca            #+#    #+#              #
#    Updated: 2024/01/25 13:02:25 by mvisca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------#
#	FORMAT				#
#-----------------------#

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
NC				:= \033[0m


#-----------------------#
#	TARGET				#
#-----------------------#

NAME			:= philo

#-----------------------#
#	SRC					#
#-----------------------#

SRCS			:=	actions.c		\
					getters.c		\
					init.c			\
					init_error.c	\
					init_validate.c	\
					life.c			\
					main.c			\
					print.c			\
					utils.c			\
					utils_time.c

#-----------------------#
#	INGREDIENTES		#
#-----------------------#

CC				:= cc
CC_FLAGS		:= -Wall -Wextra -Werror
H_FLAGS			:= -I.

#-----------------------#
#	RECIPES				#
#-----------------------#

all: $(NAME)

$(NAME): 
	@$(CC) $(CC_FLAGS) -g $(H_FLAGS) $(SRCS) -o $(NAME)
	@echo "$(BLUE)Building $(RED)$(NAME)"

clean:
	@rm -f $(NAME)
	@echo "$(YELLOW)Removing $(RED)$(NAME)"

fclean: clean

re: fclean all

.PHONY: clean fclean all


# Crear objetos y dependencias para compilar