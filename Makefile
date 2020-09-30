# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/15 13:51:51 by jecaudal          #+#    #+#              #
#    Updated: 2020/09/30 13:01:20 by Lobbyra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

HEADER			=	headers/

CFLAGS			+=	-Werror -Wall -Wextra -I ./headers/ 

CC				=	gcc

SRCS_L_PRINTF	=	./srcs/lib/simplified_printf/srcs/l_printf.c						\
					./srcs/lib/simplified_printf/srcs/pnf_apply_field.c					\
					./srcs/lib/simplified_printf/srcs/pnf_apply_prec.c					\
					./srcs/lib/simplified_printf/srcs/pnf_get_flags.c					\
					./srcs/lib/simplified_printf/srcs/pnf_get_info.c					\
					./srcs/lib/simplified_printf/srcs/pnf_get_raw.c						\
					./srcs/lib/simplified_printf/srcs/pnf_get_type.c					\
					./srcs/lib/simplified_printf/srcs/pnf_pass.c						\
					./srcs/lib/simplified_printf/additionnal_functions/l_atoi.c			\
					./srcs/lib/simplified_printf/additionnal_functions/l_free.c			\
					./srcs/lib/simplified_printf/additionnal_functions/l_itoa.c			\
					./srcs/lib/simplified_printf/additionnal_functions/l_itox.c			\
					./srcs/lib/simplified_printf/additionnal_functions/l_ptox.c			\
					./srcs/lib/simplified_printf/additionnal_functions/l_isnum.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_ispos.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_ctostr.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_isspace.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_memcpy_n.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_numlen.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_strcmp.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_putstr.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_strdup.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_strdup_n.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_strgen.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_strinject.c	\
					./srcs/lib/simplified_printf/additionnal_functions/l_strjoindel.c	\
					./srcs/lib/simplified_printf/additionnal_functions/l_strlen.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_strlen_n.c		\
					./srcs/lib/simplified_printf/additionnal_functions/l_strrev.c 		\
					./srcs/lib/simplified_printf/additionnal_functions/l_ultoa_base.c	\
					./srcs/lib/simplified_printf/additionnal_functions/l_utoa.c


OBJS_L_PRINTF	=	$(SRCS_L_PRINTF:.c=.o)

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
					./srcs/lib/ft_strlcpy.c					\
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
					./srcs/lib/ft_strdupdel_n.c				\
					./srcs/lib/ft_word_cutter.c				\
					./srcs/lib/ft_putarrstr_fd.c			\
					./srcs/lib/ft_putnbrarr_fd.c			\
					./srcs/lib/ft_strarrnuller.c			\
					./srcs/lib/ft_putarrarrstrs.c			\
					./srcs/lib/ft_get_this_word.c			\
					./srcs/lib/ft_addstr_to_strs.c			\
					./srcs/lib/ft_full_len_arrstr.c			\
					./srcs/lib/get_next_line_utils.c		\
					./srcs/lib/ft_protected_putarrstr_fd.c

OBJS_LIB		=	$(SRCS_LIB:.c=.o)

SRCS			=	./srcs/main.c									\
					./srcs/reset.c									\
					./srcs/cut_cmd.c								\
					./srcs/find_exec.c								\
					./srcs/skip_part.c								\
					./srcs/init_stock.c								\
					./srcs/free_t_stock.c							\
					./srcs/print_prompt.c							\
					./srcs/is_cmd_closed.c							\
					./srcs/error_manager.c							\
					./srcs/wait_instruction.c						\
					./srcs/check_user_input.c						\
					./srcs/check_user_input_utils.c					\
					./srcs/parsing/env_var.c						\
					./srcs/parsing/ft_itoa.c						\
					./srcs/parsing/parsing.c						\
					./srcs/parsing/get_path.c						\
					./srcs/parsing/check_pipe.c						\
					./srcs/parsing/verif_exec.c						\
					./srcs/parsing/check_quote.c					\
					./srcs/parsing/ft_intarradd.c					\
					./srcs/parsing/find_env_var.c					\
					./srcs/parsing/env_var_utils.c					\
					./srcs/parsing/command_to_jobs.c				\
					./srcs/parsing/verif_exec_utils.c				\
					./srcs/parsing/check_double_pipe.c				\
					./srcs/parsing/free_get_path_exec.c				\
					./srcs/parsing/verif_metacharacter.c			\
					./srcs/parsing/check_end_backslash.c			\
					./srcs/parsing/command_to_jobs_utils.c			\
					./srcs/parsing/check_redirection_null.c			\
					./srcs/parsing/remove_and_replace_utils.c		\
					./srcs/parsing/verif_redirection_env_var.c		\
					./srcs/parsing/spend_if_multiple_dollars.c		\
					./srcs/parsing/check_exec_after_redirection.c	\
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
					./srcs/execution/save_child_pid.c				\
					./srcs/execution/instance_builder.c				\
					./srcs/execution/redirectors_utils.c			\
					./srcs/execution/redirector_file_out.c			\
					./srcs/execution/redirector_file_in.c			\
					./srcs/execution/instance_builder_utils.c		\
					./srcs/execution/builtins/cd.c					\
					./srcs/execution/builtins/env.c					\
					./srcs/execution/builtins/pwd.c					\
					./srcs/execution/builtins/echo.c				\
					./srcs/execution/builtins/unset.c				\
					./srcs/execution/builtins/export.c				\
					./srcs/execution/builtins/ft_exit.c				\
					./srcs/execution/builtins/export_utils.c		\
					./srcs/execution/job_cleaner/pass_part.c		\
					./srcs/execution/job_cleaner/arg_cleaner.c		\
					./srcs/execution/job_cleaner/job_cleaner.c		\
					./srcs/execution/job_cleaner/part_len_quote.c	\
					./srcs/execution/job_cleaner/escaper_dquote.c	\
					./srcs/execution/job_cleaner/escaper_nquote.c	\
					./srcs/execution/job_cleaner/part_len_dquote.c	\
					./srcs/execution/job_cleaner/part_len_nquote.c

OBJS			=	$(SRCS:.c=.o)

PATH_L_PRINTF	=	srcs/lib/simplified_printf/

all				:	$(NAME)

$(NAME)			:	$(OBJS_LIB) $(OBJS)
					make -C $(PATH_L_PRINTF)
					$(CC) -o $(NAME) $(OBJS_L_PRINTF) $(OBJS_LIB) $(OBJS)

f				:	$(OBJS_LIB) $(OBJS)
					$(CC) -o $(NAME) $(OBJS_L_PRINTF) -fsanitize=address $(OBJS_LIB) $(OBJS)

clean		:
					make clean -C $(PATH_L_PRINTF)
					rm -f $(OBJS_LIB) $(OBJS_L_PRINTF) $(OBJS)

fclean		:		clean
					rm -f $(NAME)
					make fclean -C $(PATH_L_PRINTF)

re			:		fclean $(NAME)
