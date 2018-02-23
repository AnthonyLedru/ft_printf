/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:34:56 by aledru            #+#    #+#             */
/*   Updated: 2018/02/23 14:08:00 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_conversion(t_env *e, va_list arg)
{
	char arg_c;

	arg_c = (unsigned char)va_arg(arg, unsigned long long);
	if (!arg_c)
	{
		e->undefined_char_count += 1;
		e->buf = ft_strjoin(e->buf, "\0");
	}
	if (e->offset > 0)
		put_offset_precision_to_buf(e, 1);
	put_char_to_buf(arg_c, e);
	if (e->offset < 0)
		put_offset_precision_to_buf(e, 1);
}
