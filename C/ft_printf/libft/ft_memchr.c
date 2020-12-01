/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 02:35:44 by student           #+#    #+#             */
/*   Updated: 2020/05/19 02:35:57 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		cc;
	const unsigned char	*cs;
	size_t				i;

	cc = c;
	cs = s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == cc)
		{
			return ((void *)s);
		}
		i++;
		s++;
	}
	return (NULL);
}
