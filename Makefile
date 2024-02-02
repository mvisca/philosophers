# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:22:41 by mvisca            #+#    #+#              #
#    Updated: 2024/02/02 20:09:45 by mvisca-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------#
#	FORMAT				#
#-----------------------#

RED				:=	\033[0;31m

GREEN			:=	\033[0;32m

YELLOW			:=	\033[0;33m

BLUE			:=	\033[0;34m

NC				:=	\033[0m

#-----------------------#
#	TARGET				#
#-----------------------#

NAME			:=	philo

#-----------------------#
#	INGREDIENTS			#
#-----------------------#

BUILD_DIR		:=	.build/

SRCS_DIR		:=	src/

INCS_DIR		:=	inc/

HEADER			:=	philo.h

SRCS			:=	conditions.c	\
					getters.c		\
					init.c			\
					init_error.c	\
					init_validate.c	\
					life.c			\
					main.c			\
					print.c			\
					utils.c

SRCS			:=	$(SRCS:%=$(SRCS_DIR)%)

OBJS			:=	$(SRCS:$(SRCS_DIR)%.c=$(BUILD_DIR)%.o)

DEPS			:=	$(OBJS:.o=.d)

#-----------------------#
#	UTENSILIS			#
#-----------------------#

CC				:=	cc

C_FLAGS			:=	-Wall -Wextra -Werror -MMD -MP

H_FLAGS			:=	$(addprefix -I,$(INCS_DIR))

DEBUG_FLAGS		:=	-g -fsanitize=thread

RM				:=	rm -rf

DIR_DUP			:=	mkdir -p $(BUILD_DIR)

MAKEFLAGS		+=	--no-print-directory

#-----------------------#
#	RECIPES				#
#-----------------------#

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Building $(RED)$(NAME)"
	@$(CC) $(C_FLAGS) $(H_FLAGS) $(SRCS) -o $(NAME)
	@echo "$(GREEN)Linking $(NC)$(notdir $^) $(RED)-> $(NC)$(notdir $@)"
	@echo "$(GREEN)✅ DONE!"
	@$(RM) philo.d

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(DIR_DUP)
	@$(CC) $(C_FLAGS) $(H_FLAGS) -c -o $@ $<
	@echo "$(GREEN)Compiling $(NC)$(notdir $<) $(RED)-> $(NC)$(notdir $@)"
-include $(DEPS)

testobjs:
	
	@echo "$(OBJS)"
	@echo "espacio"
	@echo "$(DEPS)"

clean:
	@rm -f $(NAME)
	@echo "$(YELLOW)Removing binary $(RED)-> $(RED)$(NAME)$(NC)"

fclean: clean
	@$(RM) $(BUILD_DIR)
	@$(RM) *.dSYM
	@echo "$(YELLOW)Removing objects $(RED)-> $(NC)$(notdir $(OBJS))$(NC)"
	@echo "$(YELLOW)Removing dependencies $(RED)-> $(NC)$(notdir $(DEPS))$(NC)"
	@echo "$(YELLOW)Removing folder $(RED)-> $(NC)$(BUILD_DIR)$(NC)"

re: fclean all

.PHONY: clean fclean re all
