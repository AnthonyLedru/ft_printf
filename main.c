#include <stdio.h>
#include "includes/ft_printf.h"
#include "wchar.h"
#include <locale.h>

int main()
{
//setlocale(LC_ALL, "");
setlocale(LC_ALL, "en_US.UTF-8");

//ft_printf("%C", 4660);
//ft_printf("%c");
//ft_printf("\n");
ft_printf("%C", 'c');
ft_printf("\n");
printf("%C", 'c');
/*for(int i = 65536; i < 524287; i++)
{
	printf("%d  ", i);
	printf("%C\n", i);
}*/
}
