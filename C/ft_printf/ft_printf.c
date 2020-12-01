/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 23:23:43 by student           #+#    #+#             */
/*   Updated: 2020/09/01 23:24:02 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <unistd.h>
#include "ft_printf.h"

void	null_struct(t_flags *sflags)
{
	sflags->flag = '\0';
	sflags->star_width = '\0';
	sflags->width = 0;
	sflags->star_accur = '\0';
	sflags->accur = -1;
	sflags->type = '\0';
}

void	print_error(char error)
{
	if (error == 't')
		ft_putstr_fd("Unknown type\n", 1);
}

void	remove_stars(va_list args, t_flags *sflags)
{
	if (sflags->star_width)
		sflags->width = va_arg(args, int);
	if (sflags->star_accur)
		sflags->accur = va_arg(args, int);
}

int		add_accur(char **str_val, int length)
{
	char	*spaces;
	char	*temp;

	if (!(spaces = malloc(sizeof(char) * length + 1)))
		return (-1);
	spaces[length] = '\0';
	ft_memset(spaces, '0', length);
	temp = *str_val;
	if (!(*str_val = ft_strjoin(spaces, *str_val)))
		return (-1);
	free(spaces);
	free(temp);
	return (0);
}

int		add_space(char **str_val, int length, t_flags sflags, char c)
{
	char	*spaces;
	char	*temp;

	if (!(spaces = malloc(sizeof(char) * length + 1)))
		return (-1);
	spaces[length] = '\0';
	ft_memset(spaces, c, length);
	temp = *str_val;
	if (sflags.flag == '-')
		*str_val = ft_strjoin(*str_val, spaces);
	else
		*str_val = ft_strjoin(spaces, *str_val);
	if (!*str_val)
		return (-1);
	free(spaces);
	free(temp);
	return (0);
}

int		insert_str(char **format, char *str_val, t_coord scoord)
{
	char	*s1;
	char	*s2;
	char	*temp;

	if (!(s1 = ft_substr(*format, 0, scoord.start)))
		return (-1);
	if (!(s2 =  ft_strjoin(s1, str_val)))
		return (-1);
	free(s1);
	if (!(s1 = ft_substr(*format, scoord.end + 1, ft_strlen(*format) - scoord.end)))
		return (-1);
	temp = *format;
	if (!(*format = ft_strjoin(s2, s1)))
		return (-1);
	free(temp);
	free(s1);
	free(s2);
	return (0);
}

int		add_accur_int(char **str_val, int length, int is_width)
{
	char	*spaces;
	int		val_length;
	int		accur;
	t_coord	scoord;

	val_length = (int)ft_strlen(*str_val);
	if (str_val[0][0] == '-' && is_width == 0)
		val_length--;
	if (val_length < length)
	{
		accur = length - val_length;
		if (!(spaces = malloc(sizeof(char) * accur + 1)))
			return (-1);
		spaces[accur] = '\0';
		ft_memset(spaces, '0', accur);
		if (str_val[0][0] == '-')
		{
		scoord.start = 1;
		scoord.end = 0;
		}
		else
		{
			scoord.start = 0;
			scoord.end = -1;
		}
		
		insert_str(str_val, spaces, scoord);
	
		free(spaces);
	}
	return (0);
}

int		insert_int(char **format, va_list args, t_coord scoord, t_flags sflags)
{
	char	*str_val;
	char	dop;
	int		length;
	int		val;
	int		is_minus;

	remove_stars(args, &sflags);
	val = va_arg(args, int);
	if (val == 0 && sflags.accur == 0)
		str_val = ft_strdup("");
	else
		str_val = ft_itoa(val);
	if (str_val[0] == '-')
		is_minus = 1;
	else
		is_minus = 0;
	add_accur_int(&str_val, sflags.accur, 0);
	dop = ' ';
	if (sflags.flag == '0' && str_val[0] != '\0' && sflags.accur < 0)
		dop = '0';
	if (is_minus == 1 && sflags.flag == '0' && sflags.accur < 0)
		add_accur_int(&str_val, sflags.width, 1);
	else
	{
	if ((int)ft_strlen(str_val) < sflags.width)
		add_space(&str_val, sflags.width - ft_strlen(str_val), sflags, dop);
	}
	if (insert_str(format, str_val, scoord) < 0)
		return (-1);
	length = ft_strlen(str_val) + scoord.start;
	free(str_val);
	return (length - 1);
}

int		insert_char(char **format, va_list args, t_coord scoord, t_flags sflags)
{
	char			*str_val;
	char			dop;
	int				length;
	int				val;

	val = 1;	
	if (!(str_val = ft_strdup(" ")))
		return (-1);
	if (sflags.type == '%')
		ft_memset(str_val, '%', 1);
	else
	{
		val = (char)va_arg(args, int);
		if (val == 0)
		{
			str_val[0] = 18;
		}
		else
			ft_memset(str_val, (char)val, 1);
	}
	dop = ' ';
	if (sflags.flag == '0')
		dop = '0';
	if (val == 0)
		length = 1;
	else
		length = ft_strlen(str_val);
	if ((int)ft_strlen(str_val) < sflags.width)
		add_space(&str_val, sflags.width - length, sflags, dop);
	if (insert_str(format, str_val, scoord) < 0)
		return (-1);
	length = scoord.start + ft_strlen(str_val);
	if (str_val[0] != '\0')
		length--;
	free(str_val);
	return (length);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (1);
			i++;
		}
		if (s1[i] != s2[i])
			return (1);
		return (0);
	}
	return (-1);
}

int		insert_string(char **format, va_list args, t_coord scoord, t_flags sflags)
{
	char			*str_val;
	char			*temp;
	char			dop;
	int				length;

	remove_stars(args, &sflags);

	str_val = va_arg(args, char *);
	if (str_val == NULL)
		str_val = ft_strdup("(null)");
	else
		str_val = ft_strdup(str_val);
	dop = ' ';
	if (sflags.flag == '0')
		dop = '0';
	if (sflags.star_accur >= 0)
		if ((int)ft_strlen(str_val) > sflags.accur)
		{
			temp = str_val;
			str_val = ft_substr(str_val, 0, sflags.accur);
			free(temp);
		}
	if ((int)ft_strlen(str_val) < sflags.width)
		add_space(&str_val, sflags.width - ft_strlen(str_val), sflags, dop);
	if (insert_str(format, str_val, scoord) < 0)
		return (-1);
	length = ft_strlen(str_val) + scoord.start;
	if (str_val[0] != '\0')
		length--;
	free(str_val);
	return (length);
}

int		insert_pointer(char **format, va_list args, t_coord scoord, t_flags sflags)
{
	char	*str_val;
	char	*temp;
	char	dop;
	int		length;

	remove_stars(args, &sflags);
	if (!(str_val = (ft_pointer_itoa(va_arg(args, void *)))))
		return(-1);
	dop = ' ';
	if (sflags.flag == '0' && sflags.accur < 0)
		dop = '0';
	if ((int)ft_strlen(str_val) < sflags.accur)
		add_accur(&str_val, sflags.accur - ft_strlen(str_val));
	temp = str_val;
	str_val = ft_strjoin("0x", str_val);
	free(temp);
	if ((int)ft_strlen(str_val) < sflags.width)
		add_space(&str_val, sflags.width - ft_strlen(str_val), sflags, dop);
	if (insert_str(format, str_val, scoord) < 0)
		return (-1);
	length = ft_strlen(str_val) + scoord.start;
	free(str_val);
	return (length - 1);
}

int		insert_unsign(char **format, va_list args, t_coord scoord, t_flags sflags)
{
	char	*str_val;
	char	dop;
	int		length;
	int val;

		val = va_arg(args, int);
	if (val == 0 && sflags.accur == 0)
		str_val = ft_strdup("");
	else
	{
		str_val = ft_unsign_itoa((unsigned int)val);
	}
	dop = ' ';
	if (sflags.flag == '0' && sflags.accur < 0)
		dop = '0';
	if ((int)ft_strlen(str_val) < sflags.accur)
		add_accur(&str_val, sflags.accur - ft_strlen(str_val));
	if ((int)ft_strlen(str_val) < sflags.width)
		add_space(&str_val, sflags.width - ft_strlen(str_val), sflags, dop);
	if (insert_str(format, str_val, scoord) < 0)
		return (-1);
	length = ft_strlen(str_val) + scoord.start;
	free(str_val);
	return (length - 1);
}

void	to_upper(char **str_val)
{
	int		i;

	i = 0;
	while (str_val[0][i] != '\0')
	{
		if (str_val[0][i] >= 'a' && str_val[0][i] <= 'f')
			str_val[0][i] -= 32;
		i++;
	}
}

int		insert_hex(char **format, va_list args, t_coord scoord, t_flags sflags)
{
	char	*str_val;
	char	dop;
	int		length;
	int val;

	val = va_arg(args, int);
	if (val == 0 && sflags.accur == 0)
		str_val = ft_strdup("");
	else
	{

		str_val = ft_hex_itoa(((unsigned)val));
	}
	if (sflags.type == 'X')
		to_upper(&str_val);
	dop = ' ';
	if (sflags.flag == '0' && sflags.accur < 0)
		dop = '0';
	if ((int)ft_strlen(str_val) < sflags.accur)
		add_accur(&str_val, sflags.accur - ft_strlen(str_val));
	if ((int)ft_strlen(str_val) < sflags.width)
		add_space(&str_val, sflags.width - ft_strlen(str_val), sflags, dop);
	if (insert_str(format, str_val, scoord) < 0)
		return (-1);
	length = ft_strlen(str_val) + scoord.start;
	free(str_val);
	return (length - 1);
}

int		exception(char **format, t_coord scoord)
{
	char *temp;
	int		length;

	temp = *format;
	*format = ft_substr(*format, 0, scoord.start);
	length = ft_strlen(*format);
	free(temp);
	return (length);
}

int		insert(char **format, va_list args, t_coord scoord, t_flags sflags)
{
	int status;

	if (sflags.type == 'd' || sflags.type == 'i')
		status = insert_int(format, args, scoord, sflags);
	else if (sflags.type == 'c' || sflags.type == '%')
		status = insert_char(format, args, scoord, sflags);
	else if (sflags.type == 's')
		status = insert_string(format, args, scoord, sflags);
	else if (sflags.type == 'p')
		status = insert_pointer(format, args, scoord, sflags);
	else if (sflags.type == 'u')
		status = insert_unsign(format, args, scoord, sflags);
	else if (sflags.type == 'x' || sflags.type == 'X')
		status = insert_hex(format, args, scoord, sflags);
	else
	{
		status = exception(format, scoord);
	}
	return (status);
}

int		procent_parse_flags(char *format, int proc,
		t_flags *sflags, char *flags)
{
	char *conv;

	conv = "cspdiuxX%";
	while (ft_strchr(flags, format[++proc]))
		if (sflags->flag != '-')
			sflags->flag = format[proc];
	if (format[proc] == '*')
		sflags->star_width = format[proc++];
	else if (ft_isdigit(format[proc]))
	{
		sflags->width = ft_atoi(&(format[proc]));
		while (ft_isdigit(format[proc]))
			proc++;
	}
	if (format[proc] == '.')
	{
		sflags->accur = ft_atoi(&(format[++proc]));
		if (format[proc] == '-')
			proc++;
		while (ft_isdigit(format[proc]))
			proc++;
	}
	return (proc);
}

int		remove_stars2(char **format, va_list args, int proc)
{
	char	*conv;
	t_coord scoord;
	int		arg;

	conv = "cspdiuxX%";
	while (!(ft_strchr(conv, format[0][proc])))
	{
		if (format[0][proc] == '*')
		{
			scoord.start = proc;
			scoord.end = proc;
			arg = va_arg(args, int);
			if (arg < 0 && format[0][proc - 1] == '.')
				arg = -1;
			insert_str(format, ft_itoa(arg), scoord);
		}
		proc++;
	}
	return (0);
}

int		procent_parse(char **format, va_list args, int proc)
{
	char	*flags;
	char	*conv;
	t_flags sflags;
	t_coord scoord;

	null_struct(&sflags);
	flags = "-0";
	conv = "cspdiuxX%";
	scoord.start = proc;
	remove_stars2(format, args, proc + 1);
	proc = procent_parse_flags(*format, proc, &sflags, flags);
	if (ft_strchr(conv, format[0][proc]))
		sflags.type = format[0][proc];
	scoord.end = proc;
	return (insert(format, args, scoord, sflags));
}

int		ft_printf(const char *line, ...)
{
	va_list args;
	char	*format;
	int		proc;
	int		length;

	if (line == NULL)
		return (0);
	va_start(args, line);
	format = ft_strdup(line);
	proc = 0;
	while (format[proc] != '\0')
	{
		if (format[proc] == '%')
		{
			if ((proc = procent_parse(&format, args, proc)) < 0)
				return (-1);
		}
		proc++;
	}
	length = ft_strlen(format);
	int i = 0;
	while (i < length)
	{
		if (format[i] == 18)
			write(1, "\0", 1);
		else
		{
			write(1, &format[i], 1);
		}
		i++;		
	}
	free(format);
	return (length);
}
