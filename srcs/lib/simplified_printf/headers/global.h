/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:24:37 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 13:56:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef char	t_bool;

# define FALSE 0
# define TRUE 1
# define FAILURE 0
# define SUCCESS 1

void			l_putstr(char *s);

t_bool			l_ispos(int n);
char			*l_itoa(int n);
t_bool			l_isnum(char c);
int				l_numlen(int n);
t_bool			l_isspace(char c);
char			*l_ctostr(char c);
int				l_atoi(char *str);
char			*l_ptox(void *ptr);
unsigned int	l_strlen(char *str);
void			l_strrev(char *str);
char			*l_strdup(char *str);
void			l_free(int argc, ...);
char			*l_utoa(unsigned int n);
int				l_printf(char *str, ...);
char			*l_strgen(char c, int n);
int				l_strcmp(char *s1, char *s2);
unsigned int	l_strlen_n(char *str, int n);
char			*l_strdup_n(char *str, int n);
char			*l_itox(int hex_value, t_bool is_cap);
char			*l_strjoindel(char *s1, char *s2, int param);
void			*l_memcpy_n(void *s1, void *s2, unsigned int n);
char			*l_ultoa_base(unsigned long nbr, char *base_to);
char			*l_strinject(char *str, char *injection, unsigned int index);
#endif
