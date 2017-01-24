# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:11:07 by jmoucade          #+#    #+#              #
#    Updated: 2017/01/24 14:41:48 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes

SRC_PATH = sources

SRC =	$(SRC_PATH)/minishell.c		\
		$(SRC_PATH)/builtins.c		\
		$(SRC_PATH)/env.c		\
		$(SRC_PATH)/env_utils.c		\
		$(SRC_PATH)/binaries.c		\
		$(SRC_PATH)/tilde.c		\
		$(SRC_PATH)/builtins/exit.c			\
		$(SRC_PATH)/builtins/unsetenv.c		\
		$(SRC_PATH)/builtins/echo.c			\
		$(SRC_PATH)/builtins/clearenv.c		\
		$(SRC_PATH)/builtins/setenv.c		\
		$(SRC_PATH)/builtins/cd.c		\
		$(SRC_PATH)/builtins/printenv.c 

OSRC = $(SRC:.c=.o)

LIB_PATH = libft
LIB = libft/libft.a

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIB_PATH) -lft
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(LIB):
	@echo "Compiling libft..."
	@make -C $(LIB_PATH)
	@echo "Librairy compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIB_PATH)/$(INC_PATH) -I $(INC_PATH) -c -o $@ $?
	@echo "Linking file $@"

clean:
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OSRC)
	@echo "Cleaning temporary files."

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -f $(NAME)
	@echo "Delete $(NAME) file."

re: fclean all
