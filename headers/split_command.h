/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:22:27 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/25 13:36:07 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_COMMAND_H
# define SPLIT_COMMAND_H

void	skip_part(char **cmd);
char	**init_split(int n_args);
void	ft_putarrstr(char **argv, char *sep);
int		part_len(char *str, char first_letter);
char	*part_add(char *arg, char *cmd, int p_len);

#endif