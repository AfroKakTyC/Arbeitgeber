/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:45:15 by barla             #+#    #+#             */
/*   Updated: 2020/05/29 16:37:09 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char			*ft_strnstr(const char *haystack,
const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ptr;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			ptr = i;
			j = 0;
			while (haystack[i] == needle[j] && needle[j] != '\0' && i < len)
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[ptr]);
			i = ptr;
		}
		i++;
	}
	return (NULL);
}
