/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:24:25 by barla             #+#    #+#             */
/*   Updated: 2020/02/04 13:18:11 by barla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whitespace(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\r' ||
	ch == '\n' || ch == '\v' || ch == '\f')
		return (1);
	else
	{
		return (0);
	}
}

int			ft_atoi(const char *str)
{
	int variables[2];

	variables[0] = 0;
	variables[1] = 1;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			variables[1] = -1;
		str++;
	}
	if (*str >= '0' && *str <= '9')
	{
		variables[0] = *str - '0';
		str++;
	}
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (variables[0] * variables[1]);
		variables[0] = (variables[0] * 10) + (*str - '0');
		str++;
	}
	return (variables[0] * variables[1]);
}
