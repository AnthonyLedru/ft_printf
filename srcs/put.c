/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:31:59 by aledru            #+#    #+#             */
/*   Updated: 2018/02/20 13:00:42 by aledru           ###   ########.fr       */
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

void	ft_putoffset_count(int offset, t_env *e)
{
	int i;

	i = 0;
	if (offset < 0)
		offset *= -1;
	offset--;
	while (i < offset)
	{
		ft_putchar_count(' ', e);
		i++;
	}
}
