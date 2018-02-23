/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/02/23 17:09:32 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nb_digit(t_env *e, int base)
{
	int	nb_digit;
	unsigned long long int nbr_cp;

	nbr_cp = e->nbr;
	nb_digit = 0;
	while (nbr_cp /= base)
		nb_digit++;
	return (nb_digit + 1);
}

void	double_conversion(t_env *e)
{
	int		nb_digit;

	e->base = 10;
	nb_digit = get_nb_digit(e, 10);
	/*if (e->flag->i == 1 && e->type->i < 0)
		nb_digit++;*/
	if (e->offset > 0)
		put_offset_precision_to_buf(e, nb_digit);
	put_str_to_buf(base_converter(e, 1), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}

void	octal_conversion(t_env *e)
{
	int				nb_digit;

	nb_digit = get_nb_digit(e, 8);
	e->base = 8;
	if (e->offset >= 0)
		put_offset_precision_to_buf(e, nb_digit);
	put_str_to_buf(base_converter(e, 0), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}

void	hexa_conversion(t_env *e, int is_caps)
{
	int				nb_digit;

	nb_digit = get_nb_digit(e, 16);
	e->base = 16;
	if (e->offset >= 0)
		put_offset_precision_to_buf(e, nb_digit);
	if (is_caps == 1)
		put_str_to_buf(base_converter(e, 1), e, nb_digit, "nbr");
	else
		put_str_to_buf(base_converter(e, 0), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}
