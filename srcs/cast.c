/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:44:35 by aledru            #+#    #+#             */
/*   Updated: 2018/03/02 18:13:15 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_arg_flag(t_env *e, va_list arg)
{
	if (e->str[e->i] == 'l' && e->str[e->i + 1] != 'l')
		e->nbr = (unsigned long int)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'h' && e->str[e->i + 1] == 'd')
		e->nbr = (short int)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'l' && e->str[e->i + 1] == 'l')
	{
		e->nbr = (unsigned long long int)va_arg(arg, uintmax_t);
		e->i++;
	}
	if (e->str[e->i] == 'h' && e->str[e->i + 1] == 'h')
	{
		e->nbr = (signed char)va_arg(arg, uintmax_t);
		e->i++;
	}
	e->i++;
}

void	cast_arg(t_env *e, va_list arg)
{
	if (e->str[e->i] == 'd')
		e->nbr = (int)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'u')
		e->nbr = (unsigned int)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'U' || (e->str[e->i] == 'h' && e->str[e->i + 1] == 'U'))
		e->nbr = (unsigned long int)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'c')
		e->nbr = (unsigned char)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'X')
		e->nbr = (unsigned int)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'x')
		e->nbr = (unsigned int)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'o')
		e->nbr = (unsigned int)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'j')
		e->nbr = (uintmax_t)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'z')
		e->nbr = (size_t)va_arg(arg, uintmax_t);
	if (e->str[e->i] == 'h' || e->str[e->i] == 'l' || e->str[e->i] == 'z' ||
			e->str[e->i] == 'j')
		cast_arg_flag(e, arg);
}
