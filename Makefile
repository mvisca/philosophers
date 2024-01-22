# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:22:41 by mvisca            #+#    #+#              #
#    Updated: 2024/01/22 21:39:00 by mvisca           ###   ########.fr        #
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
					error.c			\
					init.c			\
					join.c			\
					life.c			\
					main.c			\
					print.c			\
					utils.c			\
					validate.c

#-----------------------#
#	INGREDIENTES		#
#-----------------------#

CC				:= cc

H_FLAGS			:= -I.

#-----------------------#
#	RECIPES				#
#-----------------------#

all: $(NAME)

$(NAME): 
	@$(CC) -g $(H_FLAGS) $(SRCS) -o $(NAME)
	@echo "$(BLUE)Building $(RED)$(NAME)"

clean:
	@rm -f $(NAME)
	@echo "$(YELLOW)Removing $(RED)$(NAME)"

fclean: clean

re: fclean all

.PHONY: clean fclean all


# Crear objetos y dependencias para compilar