/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:29:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/19 15:42:15 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define ERR_QUOTE1 "minishell: unexpected EOF while looking for matching `"
# define ERR_QUOTE2 "\'\nminishell: syntax error: unexpected end of file"

int		check_quote(t_stock *stock);

#endif