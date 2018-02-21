/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:31:59 by aledru            #+#    #+#             */
/*   Updated: 2018/02/21 19:39:04 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, t_env *e)
{
	ft_putchar(c);
	e->count++;
}

void	ft_putstr_count(char *str, t_env *e)
{
	while (*str)
	{
		ft_putchar_count(*str, e);
		str++;
	}
}

void	ft_putnbr_count(int nbr, t_env *e)
{
	int nbr_c;

	nbr_c = nbr;
	if (nbr < 0)
		e->count++;
	while (nbr_c / 10)
	{
		nbr_c /= 10;
		e->count++;
	}
	e->count++;
	ft_putnbr(nbr);
}

void	ft_putoffset_precision_count(t_env *e, int arg_size)
{
	int i;

	i = 0;
	if (e->offset < 0)
		e->offset *= -1;
	if (e->precision > arg_size && e->offset > e->precision)
		e->offset -= e->precision;
	else
		e->offset -= arg_size;
	while (i < e->offset)
	{
		ft_putchar_count(' ', e);
		i++;
	}
	if (e->precision > arg_size)
	{
		i = 0;
		while (i < e->precision - arg_size)
		{
			ft_putchar_count('0', e);
			i++;
		}
	}
	e->offset = 0;
}
