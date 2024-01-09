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

NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

SRCS	=	error.c \
			init.c \
			join.c \
			life.c \
			main.c \
			print.c \
			utils.c \
			validate.c	

all: $(NAME)

$(NAME): cc $(CFLAGS) $(SRCS) -o $(NAME)

fclean: clean

clean:
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
