# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 13:51:51 by jecaudal          #+#    #+#              #
#    Updated: 2020/07/16 18:05:40 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	headers/

CFLAGS			+=	-Werror -Wall -Wextra -I ./headers/

CC				=	clang

SRCS_LIB		=	./srcs/print_jobs.c						\
					./srcs/lib/ft_skip.c					\
					./srcs/lib/ft_atoi.c					\
					./srcs/lib/ft_split.c					\
					./srcs/lib/ft_isnum.c					\
					./srcs/lib/ft_putnbr.c					\
					./srcs/lib/ft_ctostr.c					\
					./srcs/lib/ft_putstr.c					\
					./srcs/lib/ft_strcmp.c					\
					./srcs/lib/ft_strdup.c					\
					./srcs/lib/ft_strlen.c					\
					./srcs/lib/ft_isspace.c					\
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
					./srcs/lib/ft_strlen_c.c				\
					./srcs/lib/ft_close_fds.c				\
					./srcs/lib/ft_putnbr_fd.c				\
					./srcs/lib/ft_strarrdup.c				\
					./srcs/lib/ft_strarrlen.c				\
					./srcs/lib/ft_strdupdel.c				\
					./srcs/lib/ft_putarrstr.c				\
					./srcs/lib/ft_putstr_fd.c				\
					./srcs/lib/ft_sort_strs.c				\
					./srcs/lib/ft_putchar_fd.c				\
					./srcs/lib/ft_strarrfree.c				\
					./srcs/lib/ft_strcleaner.c				\
					./srcs/lib/ft_skip_until.c				\
					./srcs/lib/ft_strjoindel.c				\
					./srcs/lib/get_next_line.c				\
					./srcs/lib/ft_word_cutter.c				\
					./srcs/lib/ft_putarrstr_fd.c			\
					./srcs/lib/ft_putnbrarr_fd.c			\
					./srcs/lib/ft_strarrnuller.c			\
					./srcs/lib/ft_putarrarrstrs.c			\
					./srcs/lib/ft_get_this_word.c			\
					./srcs/lib/ft_addstr_to_strs.c			\
					./srcs/lib/ft_full_len_arrstr.c			\
					./srcs/lib/ft_strlcpy.c					\
					./srcs/lib/get_next_line_utils.c		\
					./srcs/lib/ft_protected_putarrstr_fd.c

OBJS_LIB		=	$(SRCS_LIB:.c=.o)

SRCS			=	./srcs/main.c									\
					./srcs/reset.c									\
					./srcs/find_exec.c								\
					./srcs/skip_part.c								\
					./srcs/init_stock.c								\
					./srcs/free_t_stock.c							\
					./srcs/print_prompt.c							\
					./srcs/error_printer.c							\
					./srcs/wait_instruction.c						\
					./srcs/wait_instruction_utils.c					\
					./srcs/parsing/env_var.c						\
					./srcs/parsing/ft_itoa.c						\
					./srcs/parsing/parsing.c						\
					./srcs/parsing/get_path.c						\
					./srcs/parsing/check_pipe.c						\
					./srcs/parsing/verif_exec.c						\
					./srcs/parsing/check_quote.c					\
					./srcs/parsing/ft_intarradd.c					\
					./srcs/parsing/env_var_utils.c					\
					./srcs/parsing/command_to_jobs.c				\
					./srcs/parsing/remplace_env_var.c				\
					./srcs/parsing/verif_exec_utils.c				\
					./srcs/parsing/check_double_pipe.c				\
					./srcs/parsing/verif_metacharacter.c			\
					./srcs/parsing/check_end_backslash.c			\
					./srcs/parsing/command_to_jobs_utils.c			\
					./srcs/parsing/check_redirection_null.c			\
					./srcs/parsing/remove_and_replace_utils.c		\
					./srcs/parsing/verif_redirection_env_var.c		\
					./srcs/parsing/split_cmd/pass_word.c			\
					./srcs/parsing/split_cmd/split_cmd.c			\
					./srcs/parsing/split_cmd/is_escaped.c			\
					./srcs/parsing/split_cmd/pass_quote.c			\
					./srcs/parsing/split_cmd/pass_dquote.c			\
					./srcs/parsing/split_cmd/pass_spaces.c			\
					./srcs/parsing/split_cmd/is_sep_char.c			\
					./srcs/execution/execution.c					\
					./srcs/execution/init_pipes.c					\
					./srcs/execution/terminator.c					\
					./srcs/execution/redirector.c					\
					./srcs/execution/is_builtin.c					\
					./srcs/execution/close_pipes.c					\
					./srcs/execution/jobs_caller.c					\
					./srcs/execution/builtin_caller.c				\
					./srcs/execution/instance_builder.c				\
					./srcs/execution/redirectors_utils.c			\
					./srcs/execution/redirector_file_out.c			\
					./srcs/execution/redirector_file_in.c			\
					./srcs/execution/builtins/cd.c					\
					./srcs/execution/builtins/env.c					\
					./srcs/execution/builtins/pwd.c					\
					./srcs/execution/builtins/echo.c				\
					./srcs/execution/builtins/unset.c				\
					./srcs/execution/builtins/export.c				\
					./srcs/execution/builtins/ft_exit.c				\
					./srcs/execution/builtins/export_utils.c		\
					./srcs/execution/jobs_cleaner/pass_part.c		\
					./srcs/execution/jobs_cleaner/arg_cleaner.c		\
					./srcs/execution/jobs_cleaner/jobs_cleaner.c	\
					./srcs/execution/jobs_cleaner/part_len_quote.c	\
					./srcs/execution/jobs_cleaner/escaper_dquote.c	\
					./srcs/execution/jobs_cleaner/escaper_nquote.c	\
					./srcs/execution/jobs_cleaner/part_len_dquote.c	\
					./srcs/execution/jobs_cleaner/part_len_nquote.c

OBJS			=	$(SRCS:.c=.o)

PATH_L_PRINTF	=	./srcs/lib/simplified_printf/

L_PRINTF		=	-L./srcs/lib/simplified_printf -llprintf

all				:	$(NAME)

make_l_printf	:
					@make -C $(PATH_L_PRINTF)

$(NAME)			:	make_l_printf $(OBJS_LIB) $(OBJS)
					$(CC) -o $(NAME) $(L_PRINTF) $(OBJS_LIB) $(OBJS)

f				:	make_l_printf $(OBJS_LIB) $(OBJS)
					$(CC) -o $(NAME) $(L_PRINTF) -fsanitize=address $(OBJS_LIB) $(OBJS)

clean		:
					rm -f $(OBJS_LIB) $(OBJS)

fclean		:		clean
					rm -f $(NAME)
					@make fclean -C $(PATH_L_PRINTF)

re			:		fclean $(NAME)
