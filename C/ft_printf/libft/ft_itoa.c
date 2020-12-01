/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:36:56 by student           #+#    #+#             */
/*   Updated: 2020/05/24 01:37:13 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_mod(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static char	*ft_reverse(char *s)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}
	j--;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_minus;
	int		length;

	is_minus = 0;
	if (n < 0)
		is_minus = 1;
	if (!(str = malloc(sizeof(char) * 11 + is_minus)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_mod(n % 10);
		n = (n / 10);
	}
	if (is_minus)
		str[length++] = '-';
	str[length] = '\0';
	str = ft_reverse(str);
	return (str);
}

char	*ft_hex_itoa(unsigned int n)
{
	char	*str;
	int		length;

	if (!(str = malloc(sizeof(char) * 11)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	length = 0;
	while (n != 0)
	{
		if (n % 16 <= 9)
		{
			str[length++] = '0' + (n % 16);
			//printf("c = %d\n");

		}
		else
		{
			str[length++] = 'a' + ((n % 16) % 10);
		
		
		}
		n = (n / 16);
	}
	str[length] = '\0';
	str = ft_reverse(str);
	return (str);
}

char	*ft_pointer_itoa(void *p)
{
	char	*str;
	int		length;
	long unsigned n;

	n = (long)p;
	if (!(str = malloc(sizeof(char) * 13)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	length = 0;
	while (n != 0)
	{
		if (n % 16 <= 9)
			str[length++] = '0' + (n % 16);
		else
			str[length++] = 'a' + ((n % 16) % 10);
		n = (n / 16);
	}
	str[length] = '\0';
	str = ft_reverse(str);
	return (str);
}

char	*ft_unsign_itoa(unsigned int n)
{
	char	*str;
	int		length;

	if (!(str = malloc(sizeof(char) * 11)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	str[length] = '\0';
	str = ft_reverse(str);
	return (str);
}