
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	r;


	r = printf("'%10.5s'\n", NULL);

	printf("real: %d\n", r);
	printf("\n---\n");

	r = ft_printf("'%1s'\n", NULL);
	r = ft_printf("'%10.5s'\n", NULL);
}