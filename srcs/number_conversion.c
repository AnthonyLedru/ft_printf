/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/02/21 19:21:06 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nb_digit(t_env *e, char *type, int base)
{
	int	nb_digit;

	nb_digit = 0;
	init_type_cpy(e);
	if (ft_strcmp(type, "ui") == 0)
		while (e->type->ui_cpy /= base)
			nb_digit++;
	if (ft_strcmp(type, "ul") == 0)
		while (e->type->ul_cpy /= base)
			nb_digit++;
	if (ft_strcmp(type, "ll") == 0)
		while (e->type->ll_cpy /= base)
			nb_digit++;
	if (ft_strcmp(type, "uh") == 0)
		while (e->type->uh_cpy /= base)
			nb_digit++;
	if (ft_strcmp(type, "hh") == 0)
		while (e->type->hh_cpy /= base)
			nb_digit++;
	if (ft_strcmp(type, "uj") == 0)
		while (e->type->uj_cpy /= base)
			nb_digit++;
	return (nb_digit + 1);
}

void	double_conversion(t_env *e, va_list arg)
{
	int		next_arg;
	int		arg_cpy;
	int		nb_digit;

	next_arg = va_arg(arg, int);
	arg_cpy = next_arg;
	nb_digit = 0;
	while (arg_cpy /= 10)
		nb_digit++;
	if (e->offset > 0)
		ft_putoffset_precision_count(e, nb_digit + 1);
	ft_putnbr_count(next_arg, e);
	if (e->offset < 0)
		ft_putoffset_precision_count(e, nb_digit + 1);
}

void	hexa_conversion(t_env *e, va_list arg, int is_caps, char *type)
{
	int				nb_digit;

	if (ft_strcmp(type, "ui") == 0)
		e->type->ui = va_arg(arg, unsigned int);
	if (ft_strcmp(type, "ul") == 0)
		e->type->ul = va_arg(arg, unsigned long);
	if (ft_strcmp(type, "ll") == 0)
		e->type->ll = va_arg(arg, unsigned long long);
	if (ft_strcmp(type, "uh") == 0)
		e->type->uh = (unsigned short int)va_arg(arg, unsigned long long);
	if (ft_strcmp(type, "hh") == 0)
		e->type->hh = (unsigned char)va_arg(arg, unsigned long long);
	if (ft_strcmp(type, "uj") == 0)
		e->type->uj = va_arg(arg, uintmax_t);
	nb_digit = get_nb_digit(e, type, 16);
	if (e->offset >= 0)
		ft_putoffset_precision_count(e, nb_digit);
	if (is_caps == 1)
		ft_putstr_count(base_converter(e, 16, 1, type), e);
	else
		ft_putstr_count(base_converter(e, 16, 0, type), e);
	if (e->offset < 0)
		ft_putoffset_precision_count(e, nb_digit);
}
