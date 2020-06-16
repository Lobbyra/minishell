/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:37:05 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/16 14:41:37 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define GNL_LINE_READED 1
# define GNL_EOF 0
# define GNL_CTRLD 2
# define GNL_ERROR -1
# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 256
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

int		ft_strlen_c(char *str, char c);
char	*gnl_strjoin(char *s1, char *s);
char	*ft_strcut_c(char *post_buffer, char c);
char	*ft_strdup_c(char *str, char c);
int		is_a_c(char *str, char c);
int		get_next_line(int fd, char **line);

#endif
