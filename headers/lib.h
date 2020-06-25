/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:20:45 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/25 17:50:46 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "minishell.h"

t_bool	ft_c_finder(char c, char *set);

void	ft_putnbr(int nb);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_freestrs(char **strs);
void	l_printf(char *str, ...);
void	ft_strarrfree(char **strs);
void	ft_skip(char **ptr, char c);
void	ft_putnbr_fd(int nb, int fd);
void	ft_close_fds(int *fds, int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_skip_until(char **ptr, char c);
void	ft_putarrstr(char **argv, char *sep);
void	ft_putarrarrstrs(char ***ptr, int size);
void	ft_putnbrarr_fd(int *tab, int size, int fd);
void	ft_putarrstr_fd(char **argv, char *sep, int fd);
void	*ft_memcpy_n(void *s1, void *s2, unsigned int n);

char	**ft_strarrdup(char **arr);
char	**ft_split(char *str, char *charset);
char	**ft_addstr_to_strs(char **strs, char *to_add);
char	**ft_strarrnuller(char **tab, unsigned int size);

int		ft_isalnum(char c);
int		ft_strlen(char *str);
int		ft_strarrlen(char **tab);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen_c(char *str, char c);
int		ft_full_len_arrstr(char **arr);
int		ft_fdcaster(int fd_src, int fd_dst);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_protected_putarrstr_fd(char **argv, char *sep, int fd);
int		ft_strlcpy(char *dest, char *src, unsigned int size);

char    *ft_strdup(char *str);
char    *ft_basename(char *path);
char    *ft_strdupdel(char *str);
char    *ft_strcleaner(char *str);
char	*ft_get_this_word(char *str);
char    *ft_strdup_n(char *str, int n);
char    *ft_word_cutter(char *str, char *sep);
char    *ft_strjoindel(char *s1, char *s2, int param);
char	*ft_strjoin(char *s1, char *s2);

unsigned int	ft_strlen_n(char *str, int n);

#endif
