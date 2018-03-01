/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/03/01 20:08:47 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nb_digit(t_env *e)
{
	int			nb_digit;
	uintmax_t	nbr_cp;

	nbr_cp = e->nbr;
	nb_digit = 0;
	if ((intmax_t)nbr_cp < 0 && e->str[e->i] == 'd')
		nbr_cp = -nbr_cp;
	while (nbr_cp /= e->base)
		nb_digit++;
	return (nb_digit + 1);
}

void	int_conversion(t_env *e)
{
	int		nb_digit;

	e->base = 10;
	nb_digit = get_nb_digit(e);
	nb_digit -= e->nbr == 0 && e->precision == 0 &&
		e->is_precision_specified == 1 ? 1 : 0;
	e->offset -= e->precision > nb_digit ? e->precision : nb_digit;
	if ((intmax_t)e->nbr < 0)
		e->offset--;
	if (!e->minus)
		put_offset_to_buf(e);
	if (e->plus && (intmax_t)e->nbr >= 0)
		put_char_to_buf('+', e);
	if (e->str[e->i] == 'd' && (intmax_t)e->nbr > 0 && e->space && !e->plus)
		put_char_to_buf(' ', e);
	put_precision_to_buf(e, nb_digit);
	if (!(e->nbr == 0 && e->precision == 0 && e->is_precision_specified))
		put_str_to_buf(base_converter_d(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}

void	octal_conversion(t_env *e)
{
	int		nb_digit;

	e->base = 8;
	nb_digit = get_nb_digit(e);
	nb_digit -= e->nbr == 0 && e->precision == 0 &&
		e->is_precision_specified == 1 ? 1 : 0;
	e->offset -= e->precision > nb_digit ? e->precision : nb_digit;
	e->offset -= e->precision > nb_digit ? 0 : e->sharp;
	if (e->sharp && e->precision <= nb_digit)
		e->precision += nb_digit - e->precision + 1;
	if (!e->minus)
		put_offset_to_buf(e);
	if (e->nbr)
		put_precision_to_buf(e, nb_digit);
	if (!(e->nbr == 0 && e->precision == 0 && e->is_precision_specified))
		put_str_to_buf(base_converter_x_o(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}

void	hexa_conversion(t_env *e)
{
	int		nb_digit;

	e->base = 16;
	if (e->sharp && e->nbr != 0)
	{
		e->sharp = 2;
		e->offset -= 2;
		e->precision -= 2;
	}
	if (e->nbr == 0 && e->precision == 0 && e->is_precision_specified)
		e->offset++;
	nb_digit = get_nb_digit(e);
	e->offset -= e->precision > nb_digit ? e->precision : nb_digit;
	if (!e->minus)
		put_offset_to_buf(e);
	if (e->sharp && e->caps && e->nbr != 0)
		e->buf = ft_strjoin(e->buf, "0X");
	if (e->sharp && !e->caps && e->nbr != 0)
		e->buf = ft_strjoin(e->buf, "0x");
	put_precision_to_buf(e, nb_digit);
	if (!(e->nbr == 0 && e->precision == 0 && e->is_precision_specified))
		put_str_to_buf(base_converter_x_o(e), e);
	if (e->minus)
		put_offset_to_buf(e);
}
