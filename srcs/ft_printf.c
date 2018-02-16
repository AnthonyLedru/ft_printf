/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:46:07 by aledru            #+#    #+#             */
/*   Updated: 2018/02/16 22:06:06 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_until_percent(t_env *e)
{
	while (e->str[e->i] && e->str[e->i] != '%')
	{
		ft_putchar(e->str[e->i]);
		e->i++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list arg;
	t_env	*e;

	e = create_env((char*)str);
	va_start(arg, str);
	//char *s = va_arg(arg, char *);
	while (e->str[e->i])
	{
		print_until_percent(e);
		if (!e->str[e->i])
			return (e->i);
		e->i++;
		if (!e->str[e->i])
			return (e->i);
		if (e->str[e->i] == '%')
			ft_putchar('%');
		e->i++;
	}
	va_end(arg);
	return (e->i);
}
