/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/03/02 18:49:09 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_conversion(t_env *e)
{
	e->offset -= e->precision > e->nb_digit ? e->precision : e->nb_digit;
	if (e->str[e->i] == 'u')
		e->plus = 0;
	if (e->plus && (intmax_t)e->nbr >= 0)
		e->offset--;
	if ((intmax_t)e->nbr < 0 && e->zero)
		put_char_to_buf('-', e);
	if ((intmax_t)e->nbr < 0)
		e->offset--;
	if (!e->minus && !e->zero)
		put_offset_to_buf(e);
	if (e->plus && (intmax_t)e->nbr >= 0)
		put_char_to_buf('+', e);
	if ((intmax_t)e->nbr < 0 && !e->zero && e->str[e->i] != 'u')
		put_char_to_buf('-', e);
	if (e->str[e->i] == 'd' && (intmax_t)e->nbr > 0 && e->space && !e->plus)
		put_char_to_buf(' ', e);
	if (e->zero)
		put_zero_to_buf(e);
	put_precision_to_buf(e, e->nb_digit);
	if (!(e->nbr == 0 && e->precision == 0 && e->is_precision_specified))
		put_str_to_buf(base_converter_d(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}

void	octal_conversion(t_env *e)
{
	e->offset -= e->precision > e->nb_digit ? e->precision : e->nb_digit;
	e->offset -= e->precision > e->nb_digit ? 0 : e->sharp;
	if (e->sharp && e->precision <= e->nb_digit)
		e->precision += e->nb_digit - e->precision + 1;
	if (!e->minus)
		put_offset_to_buf(e);
	if (e->nbr)
		put_precision_to_buf(e, e->nb_digit);
	if (!(e->nbr == 0 && e->precision == 0 && e->is_precision_specified))
		put_str_to_buf(base_converter_x_o(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}

void	hexa_conversion(t_env *e)
{
	if (e->sharp && e->nbr != 0)
	{
		e->sharp = 2;
		e->offset -= 2;
		e->precision -= 2;
	}
	if (e->nbr == 0 && e->precision == 0 && e->is_precision_specified)
		e->offset++;
	e->offset -= e->precision > e->nb_digit ? e->precision : e->nb_digit;
	if (e->sharp && e->zero && e->caps)
		e->buf = ft_strjoin(e->buf, "0X");
	if (e->sharp && e->zero && !e->caps)
		e->buf = ft_strjoin(e->buf, "0x");
	if (!e->minus)
		put_offset_to_buf(e);
	if (e->sharp && e->caps && e->nbr != 0 && e->zero == 0)
		e->buf = ft_strjoin(e->buf, "0X");
	if (e->sharp && !e->caps && e->nbr != 0 && e->zero == 0)
		e->buf = ft_strjoin(e->buf, "0x");
	put_precision_to_buf(e, e->nb_digit);
	if (!(e->nbr == 0 && e->precision == 0 && e->is_precision_specified))
		put_str_to_buf(base_converter_x_o(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}
