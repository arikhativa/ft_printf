
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	const char *s = "%c: '%5X'\n";
	unsigned int n = -0x1;

	printf(s, 'R', n);
	ft_printf(s, 'M', n);
}
