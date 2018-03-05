/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:03:30 by aledru            #+#    #+#             */
/*   Updated: 2018/03/06 00:18:11 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_a_pre_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == '.')
		return (1);
	return (0);
}

int		is_a_flag(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == '.' || c == '%' || c == 'h' || c == 'l' ||
		c == 'j' || c == 'z' || ft_isdigit(c))
		return (1);
	return (0);
}

void	get_flags_before_converter(t_env *e)
{
	while (is_a_pre_flag(e->str[e->i]))
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
	if (!is_a_flag(e->str[e->i]))
	{
		e->i--;
		return ;
	}
	if (e->plus == 1 && e->space == 1)
		e->space = 0;
	if (e->zero == 1 && e->minus == 1)
		e->zero = 0;
	if (e->dot == 0 || e->zero != 0)
		set_offset(e->i, e);
	set_precision(e->i, e);
	if (e->space == 1 && e->offset != 0)
		e->space = 0;
	if (e->precision != 0)
		e->zero = 0;
	select_conversion(e, arg);
}
