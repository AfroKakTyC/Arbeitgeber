/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:52:35 by student           #+#    #+#             */
/*   Updated: 2020/05/20 20:52:52 by student          ###   ########.fr       */
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

static char		*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = malloc(ft_strlen(s1) + 1);
	if (s2)
	{
		while (i < ft_strlen(s1))
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	else
		return (NULL);
}

static size_t	ft_substrsize(char const *s, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			*ft_substr(char const *s,
unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	if (s == NULL)
		return (NULL);
	if ((size_t)start < ft_strlen(s))
	{
		substr = malloc(sizeof(char) * ft_substrsize(&s[start], len) + 1);
		if (substr)
		{
			i = start;
			j = -1;
			while (i < len + start && s[i] != '\0')
			{
				substr[++j] = s[i];
				i++;
			}
			substr[++j] = '\0';
			return (substr);
		}
	}
	else
		return (ft_strdup(""));
	return (NULL);
}
