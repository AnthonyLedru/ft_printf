#include <stdio.h>
#include "includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int main()
{
	wchar_t s[4];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	ft_printf("%10ls", s);
	ft_printf("\n");
	printf("%10ls", s);
	//printf("%llllllllllS", "ss");
}
