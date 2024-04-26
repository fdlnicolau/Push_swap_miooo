# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 22:59:26 by lnicolau          #+#    #+#              #
#    Updated: 2024/04/25 15:46:41 by lnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

SRCS = $(wildcard src/*.c) $(wildcard utils/*.c)
CHECK_SRCS = $(wildcard utils/*.c) src/instructions.c checker.c

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc

RM = rm -rf

all: ${NAME} ${CHECK}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${CHECK_OBJS}
	@${CC} ${CFLAGS} ${CHECK_OBJS} -o ${CHECK}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME} ${CHECK}

re: fclean all

.PHONY: all clean fclean re
