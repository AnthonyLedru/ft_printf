#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	//ft_printf("%1d", 100);
	ft_printf("%    s", "test");
	printf("\n");
	printf("%     s", "test");
	//printf("%%");
	//printf("%s%x", "ttt", 100);
	return (0);
}
