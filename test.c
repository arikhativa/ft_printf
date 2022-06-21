
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int f()
{
	int m;
	int r;
	char	*s = "'%p\n'";
	char	*v = 0;

	printf("Real: \n");
	r = printf(s, v);
	printf("Me: \n");
	m = ft_printf(s, v);

	printf("\nret: M: %d R: %d\n", m, r);
}

int main()
{
	f();
	// printf("'%%%%' - '%s'\n%", "Hey");
	// ft_printf("'%%%%' - '%s'\n%", "Hey");
}