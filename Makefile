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
