# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 10:31:47 by jecaudal          #+#    #+#              #
#    Updated: 2020/01/28 10:36:51 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	liblprintf.a

SRCS			=	./additionnal_functions/l_atoi.c		\
					./additionnal_functions/l_free.c		\
					./additionnal_functions/l_itoa.c		\
					./additionnal_functions/l_itox.c		\
					./additionnal_functions/l_utoa.c		\
					./additionnal_functions/l_ptox.c		\
					./additionnal_functions/l_ispos.c		\
					./additionnal_functions/l_isnum.c		\
					./additionnal_functions/l_ctostr.c		\
					./additionnal_functions/l_strdup.c		\
					./additionnal_functions/l_strgen.c		\
					./additionnal_functions/l_strlen.c		\
					./additionnal_functions/l_strrev.c		\
					./additionnal_functions/l_putstr.c		\
					./additionnal_functions/l_strcmp.c		\
					./additionnal_functions/l_numlen.c		\
					./additionnal_functions/l_isspace.c		\
					./additionnal_functions/l_strdup_n.c	\
					./additionnal_functions/l_strlen_n.c	\
					./additionnal_functions/l_memcpy_n.c	\
					./additionnal_functions/l_strinject.c	\
					./additionnal_functions/l_ultoa_base.c	\
					./additionnal_functions/l_strjoindel.c	\
					./srcs/l_printf.c						\
					./srcs/pnf_pass.c						\
					./srcs/pnf_get_raw.c					\
					./srcs/pnf_get_info.c					\
					./srcs/pnf_get_type.c					\
					./srcs/pnf_get_flags.c					\
					./srcs/pnf_apply_prec.c					\
					./srcs/pnf_apply_field.c

OBJS			=	$(SRCS:.c=.o)

CFLAGS			+=	-Wall -Wextra -Werror -I headers -ansi -pedantic

CC				=	gcc

all				:
					@make $(NAME)

$(NAME)			:	$(OBJS)
					ar rc $(NAME) $(OBJS)

clean			:
					rm -f $(OBJS)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all
