/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:46:07 by aledru            #+#    #+#             */
/*   Updated: 2018/02/16 20:13:04 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_until_percent(char *string)
{
	while (*string && *string != '%')
	{
		ft_putchar(*string);
		string++;
	}
}

int		ft_printf(const char *str, ...)
{
	char	*string;
	va_list arg;

	string = (char*)str;
	va_start(arg, str);
	//char *s = va_arg(arg, char *);
	print_until_percent(string);
	va_end(arg);
	return (0);
}
