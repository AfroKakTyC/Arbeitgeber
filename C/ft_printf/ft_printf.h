/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 21:20:49 by student           #+#    #+#             */
/*   Updated: 2020/09/10 21:24:24 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags
{
	char	flag;
	char	star_width;
	int		width;
	char	star_accur;
	int		accur;
	char	type;
}	t_flags;

typedef struct s_coord
{
	int		start;
	int		end;
}	t_coord;

#endif
