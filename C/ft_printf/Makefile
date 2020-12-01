# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barla <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 18:03:11 by student           #+#    #+#              #
#    Updated: 2020/09/17 18:03:26 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

all: 
	@make -C libft/
	gcc -c $(FLAGS) ft_printf.c
	cp libft/libft.a ./libftprintf.a
	ar rc libftprintf.a ft_printf.o
	ranlib libftprintf.a