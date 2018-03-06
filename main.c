#include <stdio.h>
#include "includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int main()
{
	setlocale(LC_ALL, "");
	ft_printf("%llllllllllS", "ss");
	ft_printf("\n");
	//printf("%llllllllllS", "ss");
}
