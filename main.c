#include <stdio.h>
#include "includes/ft_printf.h"
#include "wchar.h"
#include <locale.h>

int main()
{
//setlocale(LC_ALL, "");

//ft_printf("%C", 4660);
//ft_printf("%c");
//ft_printf("\n");
//printf("%lc", 0xc3a0);
setlocale(LC_ALL, "");
printf("%lc\n", (wint_t)536);
	return (0);
}
