# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 18:55:27 by mvisca-g          #+#    #+#              #
#    Updated: 2023/11/21 20:15:13 by mvisca-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: philo

philo:
	@cc	./philosophers.c \
		./philo_creator.c \
		./philo_destroy.c \
		./philo_parse.c \
		./philo_parse_error.c \
		./philo_parse_utils.c \
		./philo_time.c \
		./philo_debug.c \
		-I. -o philo # -g -fsanitize=address
	@echo "Compiling..."
	@echo "Binary 'philo' created. Success!"

clean:
	@rm philo
	@echo "Binary 'philo' deleted."

re: clean all
