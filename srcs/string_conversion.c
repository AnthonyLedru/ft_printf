/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:02:46 by aledru            #+#    #+#             */
/*   Updated: 2018/02/22 21:29:30 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_conversion(t_env *e, va_list arg)
{
	char	*next_arg;
	int		arg_size;
	char	*precise_str;

	precise_str = NULL;
	next_arg = va_arg(arg, char *);
	if (!next_arg)
		next_arg = "(null)";
	if (e->is_precision_specified == 1)
		next_arg = "";
	arg_size = ft_strlen(next_arg);
	if (e->precision < arg_size && e->precision != 0)
		e->offset += e->offset > 0 ? arg_size - e->precision :
			(arg_size - e->precision) * -1;
	if (e->offset > 0)
		put_offset_precision_to_buf(e, arg_size);
	put_str_to_buf(next_arg, e, arg_size, "str");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, arg_size);
}
