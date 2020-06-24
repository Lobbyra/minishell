# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 13:51:51 by jecaudal          #+#    #+#              #
#    Updated: 2020/06/24 15:10:52 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	headers/

CFLAGS			+=	-Wall -Wextra -I ./headers/

CC				=	gcc

SRCS_LIB		=	./srcs/print_jobs.c						\
					./srcs/lib/ft_skip.c					\
					./srcs/lib/ft_split.c					\
					./srcs/lib/ft_putnbr.c					\
					./srcs/lib/ft_putstr.c					\
					./srcs/lib/ft_strcmp.c					\
					./srcs/lib/ft_strdup.c					\
					./srcs/lib/ft_strlen.c					\
					./srcs/lib/ft_isalnum.c					\
					./srcs/lib/ft_strjoin.c					\
					./srcs/lib/ft_putchar.c					\
					./srcs/lib/ft_strncmp.c					\
					./srcs/lib/ft_basename.c				\
					./srcs/lib/ft_c_finder.c				\
					./srcs/lib/ft_fdcaster.c				\
					./srcs/lib/ft_freestrs.c				\
					./srcs/lib/ft_memcpy_n.c				\
					./srcs/lib/ft_strdup_n.c				\
					./srcs/lib/ft_strlen_n.c				\
					./srcs/lib/ft_close_fds.c				\
					./srcs/lib/ft_putnbr_fd.c				\
					./srcs/lib/ft_strarrdup.c				\
					./srcs/lib/ft_strarrlen.c				\
					./srcs/lib/ft_strdupdel.c				\
					./srcs/lib/ft_putarrstr.c				\
					./srcs/lib/ft_putstr_fd.c				\
					./srcs/lib/ft_putchar_fd.c				\
					./srcs/lib/ft_strarrfree.c				\
					./srcs/lib/ft_strcleaner.c				\
					./srcs/lib/ft_strjoindel.c				\
					./srcs/lib/get_next_line.c				\
					./srcs/lib/ft_word_cutter.c				\
					./srcs/lib/ft_putarrstr_fd.c			\
					./srcs/lib/ft_putnbrarr_fd.c			\
					./srcs/lib/ft_strarrnuller.c			\
					./srcs/lib/ft_putarrarrstrs.c			\
					./srcs/lib/ft_get_this_word.c			\
					./srcs/lib/get_next_line_utils.c		\
					./srcs/lib/ft_full_len_arrstr.c			\
					./srcs/lib/ft_strlcpy.c					\
					./srcs/lib/ft_protected_putarrstr_fd.c

OBJS_LIB		=	$(SRCS_LIB:.c=.o)

SRCS			=	./srcs/main.c									\
					./srcs/init_stock.c								\
					./srcs/free_t_stock.c							\
					./srcs/parsing/parsing.c						\
					./srcs/parsing/check_quote.c					\
					./srcs/parsing/check_pipe.c						\
					./srcs/parsing/check_end_backslash.c			\
					./srcs/parsing/env_var.c						\
					./srcs/parsing/env_var_utils.c					\
					./srcs/parsing/remplace_env_var.c				\
					./srcs/parsing/check_double_pipe.c				\
					./srcs/parsing/verif_exec.c						\
					./srcs/parsing/get_path.c						\
					./srcs/parsing/split_command/part_add.c			\
					./srcs/parsing/split_command/part_len.c			\
					./srcs/parsing/split_command/skip_part.c		\
					./srcs/parsing/split_command/init_split.c		\
					./srcs/parsing/split_command/split_command.c	\
					./srcs/execution/execution.c					\
					./srcs/error_printer.c

OBJS			=	$(SRCS:.c=.o)

PATH_L_PRINTF	=	./srcs/lib/simplified_printf/

L_PRINTF		=	-L./srcs/lib/simplified_printf -llprintf

all				:
					@echo "/!\\ Please use dev rule for now. /!\\"

make_l_printf	:
					@make -C $(PATH_L_PRINTF)

dev				:	make_l_printf $(OBJS_LIB) $(OBJS)
					$(CC) -o $(NAME) $(L_PRINTF) $(OBJS_LIB) $(OBJS)

fdev			:	make_l_printf $(OBJS_LIB) $(OBJS)
					$(CC) -o $(NAME) $(L_PRINTF) -fsanitize=address $(OBJS_LIB) $(OBJS)

dev-clean		:
					rm -f $(OBJS_LIB) $(OBJS)

dev-fclean		:	dev-clean
					rm -f $(NAME)
					@make fclean -C $(PATH_L_PRINTF)

dev-re			:	dev-clean dev
