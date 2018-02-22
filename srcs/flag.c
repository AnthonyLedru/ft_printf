/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:59:18 by aledru            #+#    #+#             */
/*   Updated: 2018/02/22 17:02:05 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_conversion_uint(t_env *e, va_list arg)
{
		e->i++;
		if (e->str[e->i] == 'X')
			hexa_conversion(e, arg, 1, "uj");
		if (e->str[e->i] == 'x')
			hexa_conversion(e, arg, 0, "uj");
}

void	select_conversion_long(t_env *e, va_list arg)
{
	e->i++;
	if (e->str[e->i] == 'l')
	{
		e->i++;
		if (e->str[e->i] == 'X')
			hexa_conversion(e, arg, 1, "ll");
		if (e->str[e->i] == 'x')
			hexa_conversion(e, arg, 0, "ll");
	}
	else
	{
		if (e->str[e->i] == 'X')
			hexa_conversion(e, arg, 1, "ul");
		if (e->str[e->i] == 'x')
			hexa_conversion(e, arg, 0, "ul");
	}
}

void	select_conversion_short(t_env *e, va_list arg)
{
	e->i++;
	if (e->str[e->i] == 'h')
	{
		e->i++;
		if (e->str[e->i] == 'X')
			hexa_conversion(e, arg, 1, "hh");
		if (e->str[e->i] == 'x')
			hexa_conversion(e, arg, 0, "hh");
	}
	else
	{
		if (e->str[e->i] == 'X')
			hexa_conversion(e, arg, 1, "uh");
		if (e->str[e->i] == 'x')
			hexa_conversion(e, arg, 0, "uh");
	}
}
