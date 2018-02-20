/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/02/20 15:56:48 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	double_conversion(t_env *e, va_list arg)
{
	int		next_arg;

	next_arg = va_arg(arg, int);
	ft_putnbr_count(next_arg, e);
}

void	hexa_conversion(t_env *e, va_list arg)
{
	unsigned int next_arg;

	next_arg = va_arg(arg, unsigned int);
	ft_putstr_count(ft_itoa_base(next_arg, 16), e);
}
