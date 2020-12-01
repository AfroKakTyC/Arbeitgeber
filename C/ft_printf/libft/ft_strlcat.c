/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 10:52:01 by student           #+#    #+#             */
/*   Updated: 2020/05/16 10:52:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

size_t			ft_strlcat(char *dst,
		const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	if (size < dstlen + 1)
		return (ft_strlen(src) + size);
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (i < size - 1)
	{
		if (src[j] == '\0')
			break ;
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + dstlen);
}
