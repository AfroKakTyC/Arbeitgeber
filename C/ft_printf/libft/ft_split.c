/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 03:46:05 by student           #+#    #+#             */
/*   Updated: 2020/05/29 14:55:19 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char		**free_mem(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static size_t	ft_counttokens(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static size_t	ft_tokensize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void		ft_writetoken(char const *s, char *s2, char c)
{
	while (*s != c && *s != '\0')
	{
		*s2 = *s;
		s++;
		s2++;
	}
	*s2 = '\0';
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	count_tokens;

	if (s == NULL)
		return (NULL);
	count_tokens = ft_counttokens(s, c);
	arr = malloc(sizeof(char *) * ft_counttokens(s, c) + 1);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < count_tokens)
	{
		while (*s == c && *s != '\0')
			s++;
		arr[i] = malloc(sizeof(char) * ft_tokensize(s, c) + 1);
		if (!arr[i])
			return (free_mem(arr, i));
		ft_writetoken((char *)s, arr[i], c);
		while (*s != c && *s != '\0')
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
