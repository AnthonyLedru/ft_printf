/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:59:18 by aledru            #+#    #+#             */
/*   Updated: 2018/02/23 18:02:52 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_conversion_without_flag(t_env *e)
{
	if (e->str[e->i] == 'd')
		double_conversion(e);
	if (e->str[e->i] == 'X')
		hexa_conversion(e, 1);
	if (e->str[e->i] == 'x')
		hexa_conversion(e, 0);
	if (e->str[e->i] == 'o')
		octal_conversion(e);
}

void	select_conversion_with_flag(t_env *e, va_list arg)
{
	if (e->str[e->i] == 'l' && e->str[e->i + 1] == 'l')
	{
		e->nbr = (unsigned long long)va_arg(arg, unsigned long long int);
		e->i++;
	}
	if (e->str[e->i] == 'h' && e->str[e->i + 1] == 'h')
	{
		e->nbr = (unsigned char)va_arg(arg, unsigned long long int);
		e->i++;
	}
	e->i++;
	select_conversion_without_flag(e);
}
