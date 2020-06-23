/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:22:27 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/23 17:08:08 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_COMMAND_H
# define SPLIT_COMMAND_H

int		part_len(char *str, char first_letter);
void	ft_putarrstr(char **argv, char *sep);
char	**init_split(int n_args);
void	skip_part(char **cmd);
char	*part_add(char *arg, char *cmd, int p_len);

#endif