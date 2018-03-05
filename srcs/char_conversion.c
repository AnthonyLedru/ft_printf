/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:34:56 by aledru            #+#    #+#             */
/*   Updated: 2018/03/06 00:21:35 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_conversion(t_env *e)
{
	e->offset--;
	if (!e->minus)
		put_offset_to_buf(e);
	if (!e->nbr)
	{
		e->count_before_buf_reset = ft_strlen(e->buf) + 1;
		e->buf = ft_strjoin(e->buf, "\0");
		write(1, e->buf, ft_strlen(e->buf) + 1);
		ft_memdel((void*)&e->buf);
		e->buf = ft_memalloc(sizeof(char));
	}
	put_char_to_buf(e->nbr, e);
	if (e->minus)
		put_offset_to_buf(e);
}

void	unicode_conversion(t_env *e)
{
	wchar_t	*unicode;

	if (e->nbr <= 127)
		char_conversion(e);
	else if (e->nbr <= 2047)
	{
		if (!(unicode = ft_memalloc(sizeof(int) * 2)))
			malloc_error();
		unicode[0] = ((e->nbr >> 6) & 31) + 192 & 2047;
		unicode[1] = ((e->nbr) & 63) + 128 & 2047;
		put_char_to_buf(unicode[0], e);
		put_char_to_buf(unicode[1], e);
	}
	else if (e->nbr <= 65535)
	{
		if (!(unicode = ft_memalloc(sizeof(int) * 3)))
			malloc_error();;
		unicode[0] = ((e->nbr >> 12) & 15) + 224 & 65535;
		unicode[1] = ((e->nbr >> 6) & 63) + 128 & 65535;
		unicode[2] = ((e->nbr) & 63) + 128 & 65535;
		put_char_to_buf(unicode[0], e);
		put_char_to_buf(unicode[1], e);
		put_char_to_buf(unicode[2], e);
	}
	else if (e->nbr <= 1114111)
	{
		if (!(unicode = ft_memalloc(sizeof(int) * 4)))
			malloc_error();
		unicode[0] = ((e->nbr >> 18) & 7) + 240 & 1114111;
		unicode[1] = ((e->nbr >> 12) & 63) + 128 & 1114111;
		unicode[2] = ((e->nbr >> 6) & 63) + 128 & 1114111;
		unicode[3] = ((e->nbr) & 63) + 128 & 1114111;
		put_char_to_buf(unicode[0], e);
		put_char_to_buf(unicode[1], e);
		put_char_to_buf(unicode[2], e);
		put_char_to_buf(unicode[3], e);
	}
}
