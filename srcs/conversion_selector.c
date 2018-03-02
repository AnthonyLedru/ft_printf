/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:01:56 by aledru            #+#    #+#             */
/*   Updated: 2018/03/02 18:21:57 by aledru           ###   ########.fr       */
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
	if (e->str[e->i] == 'u' || e->str[e->i] == 'U' || e->str[e->i] == 'd')
		int_conversion(e);
	if (e->str[e->i] == 'X' || e->str[e->i] == 'x')
		hexa_conversion(e);
	if (e->str[e->i] == 'o')
		octal_conversion(e);
}

void	select_conversion(t_env *e, va_list arg)
{
	cast_arg(e, arg);
	if (e->str[e->i] == '%')
		put_percent_to_buf(e);
	if (e->str[e->i] == 's')
		string_conversion(e, arg);
	if (e->str[e->i] == 'c')
		char_conversion(e);
	if (e->str[e->i] == 'd')
		select_number_conversion(e);
	if (e->str[e->i] == 'u' || e->str[e->i] == 'U')
		select_number_conversion(e);
	if (e->str[e->i] == 'X')
		select_number_conversion(e);
	if (e->str[e->i] == 'x')
		select_number_conversion(e);
	if (e->str[e->i] == 'o')
		select_number_conversion(e);
	if (e->str[e->i] == 'l' || e->str[e->i] == 'h' || e->str[e->i] == 'j'
			|| e->str[e->i] == 'z')
		select_number_conversion(e);
}
