/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:04:43 by aledru            #+#    #+#             */
/*   Updated: 2018/03/09 13:25:34 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	ft_printf("@main_ftprintf: %####0000 33..1d", 256);
	ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
	//ft_printf("%hhld", 128); 
	//ft_printf("%lhh", 2147483647);
	//ft_printf("%zj", 9223372036854775807);
	//ft_printf("%lhlz", 9223372036854775807);
	//ft_printf("%lhl", 9223372036854775807);
	//ft_printf("%jhd", 9223372036854775807);
	//ft_printf("%zhd", 4294967296);
	//ft_printf("%ll#x", 9223372036854775807);
	//ft_printf("% hZ%"); 
	//ft_printf("% hZ");
	//ft_printf("% h");
}
