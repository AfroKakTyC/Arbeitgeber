#include <stdio.h>
#include "libft/libft.h"
int main(void)
{
	int h = 4200;
	char *r = "%%";
	char *p = "-12";
	int i = 8;

	//int a = printf("'%c, %-c, %3c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c'\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	//int b = ft_printf("'%c, %-c, %3c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c'\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	//int a = printf("'%c'", 0);
	//int b = ft_printf("'%c'", 0);
	//int b = 0;
	//printf("\na = %d b = %d\n", a, b);
	//printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i);
	//ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i);
	/*char *test = ft_strdup("1234");
	int length = ft_strlen(test);
	int c = 0;
	test[1] = 0;
	while (c < length)
	{
		ft_printf("%c", test[c]);
		c++;
	}
	//test[1] = 0;
	printf("%s\n%d\n", test,length);
	*/
int a = -1;
int b = -1;
char *format = NULL;
//a = printf(format, (char)27);
b = ft_printf(format, (char)27);
printf("'%d' '%d'\n", a, b);
	return (0);
}