/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:01:56 by aledru            #+#    #+#             */
/*   Updated: 2018/02/23 17:11:08 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_after_percent(t_env *e, va_list arg)
{
	while (e->str[e->i] == ' ')
		e->i++;
	get_offset(e->i, e);
	get_precision(e->i, e);
	while (e->str[e->i] == ' ')
		e->i++;
	select_conversion(e, arg);
}

void	put_percent_to_buf(t_env *e)
{
	if (e->offset > 0)
		put_offset_precision_to_buf(e, 1);
	put_char_to_buf('%', e);
	if (e->offset < 0)
		put_offset_precision_to_buf(e, 1);
}

void	select_conversion_without_flag(t_env *e)
{
	if (e->str[e->i] == 'd')
		double_conversion(e);
	if (e->str[e->i] == 'X')
		hexa_conversion(e, 1);
	if (e->str[e->i] == 'x')
		hexa_conversion(e, 0);
	if (e->str[e->i] == 'o')
		octal_conversion(e);
}

void	select_conversion(t_env *e, va_list arg)
{
	if (e->str[e->i] == '%')
		put_percent_to_buf(e);
	if (e->str[e->i] == 's')
		string_conversion(e, arg);
	if (e->str[e->i] == 'c')
		char_conversion(e, arg);
	if (e->str[e->i] == 'd')
	{
		e->nbr = (unsigned int)va_arg(arg, unsigned long long int);
		select_conversion_without_flag(e);
	}
	if (e->str[e->i] == 'X')
	{
		e->nbr = (unsigned int)va_arg(arg, unsigned long long int);
		select_conversion_without_flag(e);
	}
	if (e->str[e->i] == 'x')
	{
		e->nbr = (unsigned int)va_arg(arg, unsigned long long int);
		select_conversion_without_flag(e);
	}
	if (e->str[e->i] == 'o')
	{
	
		e->nbr = (unsigned int)va_arg(arg, unsigned long long int);
		select_conversion_without_flag(e);
	}
	if (e->str[e->i] == 'l')
		if (e->str[e->i + 1] != 'l')
			e->nbr = (unsigned long)va_arg(arg, unsigned long long int);
	if (e->str[e->i] == 'h')
		if (e->str[e->i + 1] != 'h')
			e->nbr = (unsigned short int)va_arg(arg, unsigned long long int);
	if (e->str[e->i] == 'j')
		e->nbr = (uintmax_t)va_arg(arg, unsigned long long int);
	if (e->str[e->i] == 'l' || e->str[e->i] == 'h' || e->str[e->i] == 'j')
		select_conversion_flag(e, arg);
}
