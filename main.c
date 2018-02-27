#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
ft_printf("%-10x\n", 42);
ft_printf("%+u", 4294967295);
ft_printf("\n");
printf("%+u", 4294967295);
	return (0);
}
