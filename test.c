
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// printf("ch: '%10s'\n", "123");
	// printf("ch: '%-10s'\n", " 123");
	// printf("'%10d'\n", 11);
	// printf("'%4s'\n", "123");
	// printf("R: '%6s'\n", "123");
	ft_printf("M: '%06c'\n", 'c');
	// ft_printf("ch: %#- 0+123c\ndec: %d\n", 'Y', 15);
}
