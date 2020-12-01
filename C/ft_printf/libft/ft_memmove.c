/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 01:13:01 by student           #+#    #+#             */
/*   Updated: 2020/05/29 14:51:06 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (dst < src)
	{
		i = -1;
		while (++i < len)
			cdst[i] = csrc[i];
	}
	else if (dst > src)
	{
		i = len;
		while (i != 0)
		{
			i--;
			cdst[i] = csrc[i];
		}
	}
	return (dst);
}
