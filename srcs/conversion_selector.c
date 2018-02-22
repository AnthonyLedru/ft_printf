/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:01:56 by aledru            #+#    #+#             */
/*   Updated: 2018/02/22 17:01:52 by aledru           ###   ########.fr       */
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

void	select_conversion(t_env *e, va_list arg)
{
	if (e->str[e->i] == '%')
		put_percent_to_buf(e);
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
		select_conversion_uint(e, arg);
}
