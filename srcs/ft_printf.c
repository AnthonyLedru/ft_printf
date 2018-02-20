/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:46:07 by aledru            #+#    #+#             */
/*   Updated: 2018/02/20 11:56:13 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_until_percent(t_env *e)
{
	while (e->str[e->i] && e->str[e->i] != '%')
	{
		ft_putchar_count(e->str[e->i], e);
		e->i++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list arg;
	t_env	*e;

	va_start(arg, str);
	e = create_env((char*)str);
	//char *s = va_arg(arg, char *);
	while (e->str[e->i])
	{
		print_until_percent(e);
		if (!e->str[e->i])
			return (e->count);
		e->i++;
		if (!e->str[e->i])
			return (e->count);
		check_conversion(e, arg);
		e->i++;
	}
	va_end(arg);
	return (e->count);
}
