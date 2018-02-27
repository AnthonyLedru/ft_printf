#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
ft_printf("%5d\n", -42);
ft_printf("%lu\n", -42);
ft_printf("%+u\n", 4294967295);
printf("%+u\n", 4294967295);
printf("%5d\n", -42);
	return (0);
}
