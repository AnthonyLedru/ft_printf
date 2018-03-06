#include <stdio.h>
#include "includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int main()
{
	setlocale(LC_ALL, "");
	//ft_printf("%C", 0xd800);
	/*int i = 128;
	int p = 255;
	while (i <= p)
	{
		printf("%d" , ft_printf("%C  ", i));
		i++;
	}*/
	
	ft_printf("yo%2C   %-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	ft_printf("\n");
	printf("yo%2C   %-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//printf("%d", printf("%C", 0xd800));
}
