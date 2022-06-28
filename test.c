
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	r;


	r = printf("'%.p'\n", NULL);
	r = printf("'%.1p'\n", NULL);
	r = printf("'%1p'\n", NULL);
	r = printf("'%1.1p'\n", NULL);

	r = printf("'%10p'\n", NULL);
	r = printf("'%.10p'\n", NULL);

	printf("real: %d\n", r);
	printf("\n---\n");

	r = ft_printf("'%.p'\n", NULL);
	r = ft_printf("'%.1p'\n", NULL);
	r = ft_printf("'%1p'\n", NULL);
	r = ft_printf("'%1.1p'\n", NULL);

	r = ft_printf("'%10p'\n", NULL);
	r = ft_printf("'%.10p'\n", NULL);



}