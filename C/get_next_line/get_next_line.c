/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:30:03 by student           #+#    #+#             */
/*   Updated: 2020/08/28 23:30:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cut_static(char **n_pointer, char *static_line, char **line)
{
	int		i;

	*n_pointer = NULL;
	i = -1;
	if (static_line)
		if ((*n_pointer = ft_strchr(static_line, '\n')))
		{
			*(*n_pointer)++ = '\0';
			if (!(*line = ft_strdup(static_line)))
				return (-1);
			while ((*n_pointer)[++i] != '\0')
				static_line[i] = (*n_pointer)[i];
			static_line[i] = '\0';
		}
		else
		{
			if (!(*line = ft_strdup(static_line)))
				return (-1);
			while (static_line[++i] != '\0')
				static_line[i] = '\0';
		}
	else if (!(*line = ft_strdup("")))
		return (-1);
	return (1);
}

void	free_static(char **static_line)
{
	free(*static_line);
	*static_line = NULL;
}

int		copy_remainer(char **n_pointer, char **static_line)
{
	*(*n_pointer) = '\0';
	*n_pointer = *n_pointer + 1;
	free(*static_line);
	if (!(*static_line = ft_strdup(*n_pointer)))
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*static_line;
	char		buf[BUFFER_SIZE + 1];
	char		*n_pointer;
	char		*tmp;
	int			read_bytes;

	read_bytes = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	if (cut_static(&n_pointer, static_line, line) == -1)
		return (-1);
	while (!n_pointer && (read_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_bytes] = '\0';
		if ((n_pointer = ft_strchr(buf, '\n')))
			if (copy_remainer(&n_pointer, &static_line) == -1)
				return (-1);
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)))
			return (-1);
		free(tmp);
	}
	if (n_pointer == NULL && read_bytes == 0)
		free_static(&static_line);
	return ((read_bytes > 0) ? 1 : read_bytes);
}
