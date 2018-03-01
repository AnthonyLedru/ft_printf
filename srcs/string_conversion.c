/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:02:46 by aledru            #+#    #+#             */
/*   Updated: 2018/03/01 17:11:01 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_conversion(t_env *e, va_list arg)
{
	char	*next_arg;
	int		arg_size;
	char	*precise_str;
	int		i;

	precise_str = NULL;
	next_arg = va_arg(arg, char *);
	if (!next_arg)
		next_arg = "(null)";
	arg_size = ft_strlen(next_arg);
	if (e->precision < arg_size && e->is_precision_specified == 1)
	{
		i = -1;
		e->offset -= e->precision;
		if (!(precise_str = ft_memalloc(sizeof(char) * e->precision + 1)))
			malloc_error();
		while (++i < e->precision)
			precise_str[i] = next_arg[i];
	}
	else
	{
		e->offset -= arg_size;
		precise_str = next_arg;
	}
	if (!e->minus)
		put_offset_to_buf(e);
	put_str_to_buf(precise_str, e);
	if (e->minus)
		put_offset_to_buf(e);
}