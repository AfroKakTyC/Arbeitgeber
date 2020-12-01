/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:13:21 by student           #+#    #+#             */
/*   Updated: 2020/05/20 18:13:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <errno.h>
#include <stdlib.h>

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cb;

	i = 0;
	cb = b;
	while (i < len)
	{
		*cb = (unsigned char)c;
		cb++;
		i++;
	}
	return (b);
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count != 0)
	{
		if (SIZE_MAX / count < size)
		{
			errno = ENOMEM;
			return (NULL);
		}
	}
	mem = malloc(count * size);
	if (mem)
	{
		ft_memset(mem, 0, count * size);
		return (mem);
	}
	else
		return (NULL);
}
