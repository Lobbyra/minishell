# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecaudal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/11 15:56:37 by jecaudal          #+#    #+#              #
#    Updated: 2020/06/11 16:18:07 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

HEADER		=	headers/

CFLAGS		+=	-Wall -Wextra -Werror

CFLAGS_DEV	=	-Wall -Wextra

CC			=	gcc

dev			:
				$(CC) $(CFLAGS_DEV) -o $(NAME) -I $(HEADER) $(shell find srcs -name "*.c")

dev-clean	:
				rm $(NAME)
