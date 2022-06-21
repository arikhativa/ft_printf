
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int f()
{
	int m;
	int r;

	r = printf("'%%%% %c %c %c '\n", 0, 0, '1');
	m = ft_printf("'%%%% %c %c %c '\n",0, 0, '1');

	printf("ret: M: %d R: %d\n", m, r);
}

int main()
{
	f();
	// printf("'%%%%' - '%s'\n%", "Hey");
	// ft_printf("'%%%%' - '%s'\n%", "Hey");
}