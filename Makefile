all: philo

philo:
	@cc	./philosophers.c \
		./philo_parse.c \
		./philo_parse_error.c \
		./philo_parse_utils.c \
		./philo_time.c \
		./philo_debug.c \
		-I. -o philo -g -fsanitize=address
	@echo "Compiling..."
	@echo "Binary 'philo' created. Success!"

clean:
	@rm philo
	@echo "Binary 'philo' deleted."

re: clean all
