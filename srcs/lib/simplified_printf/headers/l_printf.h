/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:14:54 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 14:50:55 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_PRINTF_H
# define L_PRINTF_H

/*
** Vocabulary :
** 		- type : Is the conversion character ID (ex : c, s, d, u, i, p)
**		- flag : Is the final type value of field len application on argument.
*/

# include "global.h"
# include <stdio.h>

/*
** ### PNF TYPEDEF ###
*/

typedef int				t_pnf_type;
typedef unsigned int	t_pnf_flags;

typedef struct			s_pnf_infos
{
	t_pnf_type			type;
	t_pnf_flags			flags;
	char				*raw;
	int					prec_len;
	int					field_len;
}						t_pnf_infos;

/*
** ### PNF DEFINES ###
*/

# define FLAG_FIELD 1
# define FLAG_PREC 2
# define FLAG_ZERO 4
# define FLAG_MINUS 8
# define FLAG_CHARNULL 16

# define TYPE_CHAR 1
# define TYPE_STR 2
# define TYPE_PTR 4
# define TYPE_INT 8
# define TYPE_UINT 16
# define TYPE_HEXMIN 32
# define TYPE_HEXCAP 64
# define TYPE_POURC 128
# define TYPE_OTHER 256

/*
** ### PNF_PROTOTYPE ###
*/
t_pnf_flags				pnf_get_flags(char *str);
t_pnf_infos				*pnf_get_info(char *str, va_list args);
char					*pnf_get_raw(t_pnf_infos *infos, va_list args);
t_pnf_type				pnf_get_type(char *s, t_bool is_field, t_bool is_prec);

char					*pnf_add_prec(char *raw, int prec);
char					*pnf_add_field(char *raw, int field_len);

void					pnf_pass_prec(char **str);
void					pnf_pass_field(char **str);
void					pnf_pass_trash(char **str);
void					pnf_pass_conv(char **str, t_pnf_flags flags);

void					pnf_apply_prec(t_pnf_infos *info);
void					pnf_apply_field(t_pnf_infos *stock);

#endif
