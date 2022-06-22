
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char *s = "5%.1s";
	char *v = "";
	int	real;
	int	me;

	real = printf(s, v);
	printf("\n\n");
	me = ft_printf(s, v);
	printf("\n\nRead: %d\nME: %d\n", real, me);
}