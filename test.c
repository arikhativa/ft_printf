
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	r;


	r = printf("'%.1i'\n", 0);
	r = printf("'%.0i'\n", 0);

	printf("real: %d\n", r);
	printf("\n---\n");

	r = ft_printf("'%.1i'\n", 0);
	r = ft_printf("'%.0i'\n", 0);


}