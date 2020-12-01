/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 01:11:29 by student           #+#    #+#             */
/*   Updated: 2020/05/23 01:11:40 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

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

static size_t	ft_isset(char s, char const *set)
{
	while (*set != '\0')
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_start(const char *s, char const *set)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(ft_isset(s[i], set)))
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_end(const char *s, char const *set)
{
	size_t i;

	if (ft_strlen(s) > 0)
	{
		i = ft_strlen(s) - 1;
		while (i > ft_start(s, set))
		{
			if (!(ft_isset(s[i], set)))
				return (i);
			i--;
		}
	}
	else
		i = ft_strlen(s);
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_end(s1, set) - ft_start(s1, set) + 2));
	if (!(s2))
		return (NULL);
	i = ft_start(s1, set);
	j = 0;
	while (i <= ft_end(s1, set))
	{
		s2[j] = s1[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
