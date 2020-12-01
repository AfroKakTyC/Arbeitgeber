/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:48:53 by student           #+#    #+#             */
/*   Updated: 2020/06/02 16:49:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		cut_static(char **n_pointer, char *static_line, char **line);
void	free_static(char **static_line);
int		get_next_line(int fd, char **line);
int		copy_remainer(char **n_pointer, char **static_line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif
