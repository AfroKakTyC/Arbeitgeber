# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barla <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 19:57:35 by student           #+#    #+#              #
#    Updated: 2020/05/29 15:42:33 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): compile

compile: $(SOURCE)
	ar rc $(NAME) $(SOURCE)

ft_atoi.o: ft_atoi.c
	gcc -c $(FLAGS) ft_atoi.c

ft_bzero.o: ft_bzero.c
	gcc -c $(FLAGS) ft_bzero.c

ft_calloc.o: ft_calloc.c
	gcc -c $(FLAGS) ft_calloc.c

ft_isalnum.o: ft_isalnum.c
	gcc -c $(FLAGS) ft_isalnum.c

ft_isalpha.o: ft_isalpha.c
	gcc -c $(FLAGS) ft_isalpha.c

ft_isascii.o: ft_isascii.c
	gcc -c $(FLAGS) ft_isascii.c

ft_isdigit.o: ft_isdigit.c
	gcc -c $(FLAGS) ft_isdigit.c

ft_isprint.o: ft_isprint.c
	gcc -c $(FLAGS) ft_isprint.c

ft_itoa.o: ft_itoa.c
	gcc -c $(FLAGS) ft_itoa.c

ft_memccpy.o: ft_memccpy.c
	gcc -c $(FLAGS) ft_memccpy.c

ft_memchr.o: ft_memchr.c
	gcc -c $(FLAGS) ft_memchr.c

ft_memcmp.o: ft_memcmp.c
	gcc -c $(FLAGS) ft_memcmp.c

ft_memcpy.o: ft_memcpy.c
	gcc -c $(FLAGS) ft_memcpy.c

ft_memmove.o: ft_memmove.c
	gcc -c $(FLAGS) ft_memmove.c

ft_memset.o: ft_memset.c
	gcc -c $(FLAGS) ft_memset.c

ft_putchar_fd.o: ft_putchar_fd.c
	gcc -c $(FLAGS) ft_putchar_fd.c

ft_putendl_fd.o: ft_putendl_fd.c
	gcc -c $(FLAGS) ft_putendl_fd.c

ft_putnbr_fd.o: ft_putnbr_fd.c
	gcc -c $(FLAGS) ft_putnbr_fd.c

ft_putstr_fd.o: ft_putstr_fd.c
	gcc -c $(FLAGS) ft_putstr_fd.c

ft_split.o: ft_split.c
	gcc -c $(FLAGS) ft_split.c

ft_strchr.o: ft_strchr.c
	gcc -c $(FLAGS) ft_strchr.c

ft_strdup.o: ft_strdup.c
	gcc -c $(FLAGS) ft_strdup.c

ft_strjoin.o: ft_strjoin.c
	gcc -c $(FLAGS) ft_strjoin.c

ft_strlcat.o: ft_strlcat.c
	gcc -c $(FLAGS) ft_strlcat.c

ft_strlcpy.o: ft_strlcpy.c
	gcc -c $(FLAGS) ft_strlcpy.c

ft_strlen.o: ft_strlen.c
	gcc -c $(FLAGS) ft_strlen.c

ft_strmapi.o: ft_strmapi.c
	gcc -c $(FLAGS) ft_strmapi.c

ft_strncmp.o: ft_strncmp.c
	gcc -c $(FLAGS) ft_strncmp.c

ft_strnstr.o: ft_strnstr.c
	gcc -c $(FLAGS) ft_strnstr.c

ft_strrchr.o: ft_strrchr.c
	gcc -c $(FLAGS) ft_strrchr.c

ft_strtrim.o: ft_strtrim.c
	gcc -c $(FLAGS) ft_strtrim.c

ft_substr.o: ft_substr.c
	gcc -c $(FLAGS) ft_substr.c

ft_tolower.o: ft_tolower.c
	gcc -c $(FLAGS) ft_tolower.c

ft_toupper.o: ft_toupper.c
	gcc -c $(FLAGS) ft_toupper.c

clean:
	rm -rf $(SOURCE)

fclean: clean
	rm -rf $(NAME)

re: fclean all
