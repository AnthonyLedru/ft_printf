/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/02/27 10:27:09 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nb_digit(t_env *e)
{
	int			nb_digit;
	uintmax_t	nbr_cp;

	nbr_cp = e->nbr;
	nb_digit = 0;
	while (nbr_cp /= e->base)
		nb_digit++;
	return (nb_digit + 1);
}

void	int_conversion(t_env *e)
{
	int		nb_digit;

	e->base = 10;
	nb_digit = get_nb_digit(e);
	if (e->str[e->i] == 'd' && e->space && (intmax_t)e->nbr >= 0
			&& !e->plus && !e->minus)
		e->buf = ft_strjoin(e->buf, " ");
	if (e->offset > 0 || e->precision > 0)
		put_offset_precision_to_buf(e, nb_digit);
	put_str_to_buf(base_converter_d(e), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}

void	octal_conversion(t_env *e)
{
	int		nb_digit;

	e->base = 8;
	if (e->sharp)
		e->sharp = 1;
	nb_digit = get_nb_digit(e);
	if (e->offset >= 0)
		put_offset_precision_to_buf(e, nb_digit);
	put_str_to_buf(base_converter_o(e), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}

void	hexa_conversion(t_env *e)
{
	int		nb_digit;

	e->base = 16;
	if (e->sharp)
		e->sharp = 2;
	nb_digit = get_nb_digit(e);
	if (e->offset >= 0)
		put_offset_precision_to_buf(e, nb_digit);
	put_str_to_buf(base_converter_x(e), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}
