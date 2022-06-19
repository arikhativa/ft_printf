
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	const char *s = "%c: '%p'\n";
	unsigned int n = 255;

	printf(s, 'R', &n);
	ft_printf(s, 'M', &n);
}
