/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:03:30 by aledru            #+#    #+#             */
/*   Updated: 2018/03/02 15:38:10 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_not_a_converter(char c)
{
	if (c == 'd' || c == 'x' || c == 'X' || c == 'o' || c == 'c' ||
		c == 'j' || c == 'z' || c == 'l' || c == 'h' || c == 'u' || c == 's')
		return (0);
	return (1);
}

int		is_digit_except_0(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

void	get_flags_before_converter(t_env *e)
{
	while (!is_digit_except_0(e->str[e->i]) && is_not_a_converter(e->str[e->i])
			&& e->str[e->i + 1])
	{
		if (e->str[e->i] == '#')
			e->sharp = 1;
		if (e->str[e->i] == '0')
			e->zero = 1;
		if (e->str[e->i] == '-')
			e->minus = 1;
		if (e->str[e->i] == ' ')
			e->space = 1;
		if (e->str[e->i] == '+')
			e->plus = 1;
		if (e->str[e->i] == '.')
		{
			e->dot = 1;
			e->is_precision_specified = 1;
			e->i++;
			break ;
		}
		e->i++;
	}
}

void	parse_after_percent(t_env *e, va_list arg)
{
	reset_var(e);
	get_flags_before_converter(e);
	if (e->plus == 1 && e->space == 1)
		e->space = 0;
	if (e->zero == 1 && e->minus == 1)
		e->zero = 0;
	if (e->dot == 0 || e->zero != 0)
		get_offset(e->i, e);
	get_precision(e->i, e);
	if (e->space == 1 && e->offset != 0)
		e->space = 0;
	if (e->precision != 0)
		e->zero = 0;
	select_conversion(e, arg);
}
