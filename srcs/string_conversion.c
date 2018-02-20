/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:02:46 by aledru            #+#    #+#             */
/*   Updated: 2018/02/20 11:47:45 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_conversion(t_env *e, va_list arg)
{
	char *next_arg;

	next_arg = va_arg(arg, char *);
	if (!next_arg)
		arg_error();
	ft_putstr_count(next_arg, e);
}
