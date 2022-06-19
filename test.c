
#include <stdio.h>
#include "ft_printf.h"

void	itoa_base(int n, char *base_str, char *ret);


int main()
{
	const char *s = "%c: '% +5d'\n";
	int n = 11;

	printf(s, 'R', n);
	ft_printf(s, 'M', n);
}
