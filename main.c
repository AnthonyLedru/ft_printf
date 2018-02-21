#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	//ft_printf("%1d", 100);
	//printf("a %d\n", -30);
	//printf("b %x\n", 4294967266);
	ft_printf("%010x", 542);
	printf("\n");
	printf("%010x", 542);
	//printf("%%");
	//printf("%s%x", "ttt", 100);
	return (0);
}
