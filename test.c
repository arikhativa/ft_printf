
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char *s1 = "1: '% 2d'\n";
	char *s2 = "2: '%-10.5d'\n";
	char *s3 = "3: '%.5d'\n";
	char *s4 = "4: '%10.2d'\n";
	char *s5 = "5: '%.2d'\n";
	int v = -123;
	int	real;
	int	me;

	real = printf(s1, v);
	real = printf(s2, v);
	real = printf(s3, v);
	real = printf(s4, v);
	real = printf(s5, v);
	printf("\n\n");
	real = ft_printf(s1, v);
	real = ft_printf(s2, v);
	real = ft_printf(s3, v);
	real = ft_printf(s4, v);
	real = ft_printf(s5, v);
	// me = ft_printf(s, v);
	// printf("\n\nRead: %d\nME: %d\n", real, me);
}

// int main()
// {
// 	char *s1 = "1: '%010s'\n";
// 	char *s2 = "2: '%10.5s'\n";
// 	char *s3 = "3: '%.5s'\n";
// 	char *s4 = "4: '%10.2s'\n";
// 	char * v = "123";
// 	int	real;
// 	int	me;

// 	real = printf(s1, v);
// 	real = printf(s2, v);
// 	real = printf(s3, v);
// 	real = printf(s4, v);
// 	printf("\n\n");
// 	// me = ft_printf(s, v);
// 	// printf("\n\nRead: %d\nME: %d\n", real, me);
// }