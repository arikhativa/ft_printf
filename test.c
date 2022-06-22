
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

// int main()
// {
// 	char *s1 = "1: '% 2u'\n";
// 	char *s2 = "2: '%-10.5u'\n";
// 	char *s3 = "3: '%.5u'\n";
// 	char *s4 = "4: '%10.2u'\n";
// 	char *s5 = "5: '%.2u'\n";
// 	size_t v = 123;
// 	int	real;
// 	int	me;

// 	real = printf(s1, v);
// 	real = printf(s2, v);
// 	real = printf(s3, v);
// 	real = printf(s4, v);
// 	real = printf(s5, v);
// 	printf("\n\n");
// 	real = ft_printf(s1, v);
// 	real = ft_printf(s2, v);
// 	real = ft_printf(s3, v);
// 	real = ft_printf(s4, v);
// 	real = ft_printf(s5, v);
// }

int main()
{
	char *s1 = "1: '%010s'\n";
	char *s2 = "2: '%10.5s'\n";
	char *s3 = "3: '%.5s'\n";
	char *s4 = "4: '%10.2s'\n";
	char * v = "123";
	int	real;
	int	me;

	real = printf(s1, v);
	real = printf(s2, v);
	real = printf(s3, v);
	real = printf(s4, v);
	printf("\n\n");
	real = ft_printf(s1, v);
	real = ft_printf(s2, v);
	real = ft_printf(s3, v);
	real = ft_printf(s4, v);
}