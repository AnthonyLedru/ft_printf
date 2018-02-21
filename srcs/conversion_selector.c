/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:01:56 by aledru            #+#    #+#             */
/*   Updated: 2018/02/21 18:47:07 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_space(t_env *e)
{
	while (e->str[e->i] == ' ')
		e->i++;
}

void	put_percent(t_env *e)
{
	if (e->offset > 0)
		ft_putoffset_precision_count(e, 1);
	ft_putchar_count('%', e);
	if (e->offset < 0)
		ft_putoffset_precision_count(e, 1);
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

void	select_conversion(t_env *e, va_list arg)
{
	if (e->str[e->i] == '%')
		put_percent(e);
	if (e->str[e->i] == 's')
		string_conversion(e, arg);
	if (e->str[e->i] == 'd')
		double_conversion(e, arg);
	if (e->str[e->i] == 'X')
		hexa_conversion(e, arg, 1, "ui");
	if (e->str[e->i] == 'x')
		hexa_conversion(e, arg, 0, "ui");
	if (e->str[e->i] == 'l')
		select_conversion_long(e, arg);
	if (e->str[e->i] == 'h')
		select_conversion_short(e, arg);
	if (e->str[e->i] == 'j')
	{
		e->i++;
		if (e->str[e->i] == 'X')
			hexa_conversion(e, arg, 1, "uj");
		if (e->str[e->i] == 'x')
			hexa_conversion(e, arg, 0, "uj");
	}
}
