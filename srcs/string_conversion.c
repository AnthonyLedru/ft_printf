/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:02:46 by aledru            #+#    #+#             */
/*   Updated: 2018/02/21 18:47:42 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_conversion(t_env *e, va_list arg)
{
	char *next_arg;

	next_arg = va_arg(arg, char *);
	if (!next_arg)
		ft_putstr_count("(null)", e);
	else
	{
		if (e->offset > 0)
			ft_putoffset_precision_count(e, ft_strlen(next_arg));
		ft_putstr_count(next_arg, e);
		if (e->offset < 0)
			ft_putoffset_precision_count(e, ft_strlen(next_arg));
	}
}
