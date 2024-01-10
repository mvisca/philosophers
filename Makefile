# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:22:41 by mvisca            #+#    #+#              #
#    Updated: 2024/01/09 17:22:42 by mvisca           ###   ########.fr        #
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

SRCS			:=	debug.c \
					error.c \
					init.c \
					join.c \
					life.c \
					main.c \
					print.c \
					utils.c \
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
	@$(CC) $(H_FLAGS) $(SRCS) -o $(NAME)
	@echo "$(BLUE)Building $(RED)$(NAME)"

clean:
	@rm -f $(NAME)

fclean: clean
	@echo "$(YELLOW)Removing $(RED)$(NAME)"

re: fclean all

.PHONY: clean fclean all
