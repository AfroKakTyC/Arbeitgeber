/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 00:10:36 by student           #+#    #+#             */
/*   Updated: 2020/05/26 00:10:50 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	ft_num_length(int n)
{
	long	length;
	long	nb;

	nb = n;
	length = 1;
	if (nb < 0)
	{
		length++;
		nb = nb * (-1);
	}
	while (nb >= 10)
	{
		length++;
		nb = nb / 10;
	}
	return (length);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	i;
	long	razr;
	long	nb;

	nb = n;
	razr = 1;
	i = 0;
	while (i < ft_num_length(nb) - 1)
	{
		razr = razr * 10;
		i++;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
		razr = razr / 10;
	}
	while (razr >= 10)
	{
		ft_putchar_fd((nb / razr) + '0', fd);
		nb = nb % razr;
		razr = razr / 10;
	}
	ft_putchar_fd(nb + '0', fd);
}
