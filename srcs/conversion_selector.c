/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:01:56 by aledru            #+#    #+#             */
/*   Updated: 2018/03/06 00:20:41 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_percent_to_buf(t_env *e)
{
	e->offset--;
	if (!e->minus)
		put_offset_to_buf(e);
	put_char_to_buf('%', e);
	if (e->minus)
		put_offset_to_buf(e);
}

void	select_number_conversion(t_env *e)
{
	set_base(e);
	set_nb_digit(e);
	e->caps = e->str[e->i] == 'X' ? 1 : 0;
	e->sharp = e->str[e->i] == 'p' ? 1 : e->sharp;
	if (e->str[e->i] == 'u' || e->str[e->i] == 'U' || e->str[e->i] == 'd' ||
			e->str[e->i] == 'D' || e->str[e->i] == 'i')
		int_conversion(e);
	if (e->str[e->i] == 'X' || e->str[e->i] == 'x' || e->str[e->i] == 'p')
		hexa_conversion(e);
	if (e->str[e->i] == 'o')
		octal_conversion(e);
}

void	select_conversion(t_env *e, va_list arg)
{
	cast_arg(e, arg);
	if (e->str[e->i] == '%')
		put_percent_to_buf(e);
	if (e->str[e->i] == 's' || e->str[e->i] == 'S')
		string_conversion(e, arg);
	if (e->str[e->i] == 'c')
		char_conversion(e);
	if (e->str[e->i] == 'C')
		unicode_conversion(e);
	if (e->str[e->i] == 'd' || e->str[e->i] == 'D' ||
		e->str[e->i] == 'u' || e->str[e->i] == 'U' ||
		e->str[e->i] == 'X' || e->str[e->i] == 'x' ||
		e->str[e->i] == 'o' || e->str[e->i] == 'p' ||
		e->str[e->i] == 'l' || e->str[e->i] == 'h' ||
		e->str[e->i] == 'j' || e->str[e->i] == 'z' ||
		e->str[e->i] == 'i')
		select_number_conversion(e);
}
