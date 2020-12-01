/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 01:56:41 by student           #+#    #+#             */
/*   Updated: 2020/05/22 01:56:53 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static size_t	writestr(size_t i, size_t j, char *s3, char const *s)
{
	while (i < ft_strlen(s))
	{
		s3[j] = s[i];
		i++;
		j++;
	}
	return (j);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (s3)
	{
		i = 0;
		j = 0;
		j = writestr(i, j, s3, s1);
		i = 0;
		j = writestr(i, j, s3, s2);
		s3[j] = '\0';
		return (s3);
	}
	return (NULL);
}
