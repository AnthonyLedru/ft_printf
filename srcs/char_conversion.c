/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:34:56 by aledru            #+#    #+#             */
/*   Updated: 2018/03/06 20:17:51 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_unicode_offset(t_env *e)
{
	if ((e->nbr > 127 && e->nbr <= 2047))
		e->offset -= 2;
	if (e->nbr > 2047 && e->nbr <= 65535)
		e->offset -= 3;
	if (e->nbr > 65535 && e->nbr <= 1114111)
		e->offset -= 4;
}

static int		get_unicode_error(t_env *e)
{
	if ((e->nbr >= 55296 && e->nbr <= 57343))
		e->unicode_error = 1;
	if ((e->nbr > 127 && e->nbr <= 2047) && MB_CUR_MAX < 2)
		e->unicode_error = 1;
	if (e->nbr > 2047 && e->nbr <= 65535 && MB_CUR_MAX < 3)
		e->unicode_error = 1;
	if (e->nbr > 65535 && e->nbr <= 1114111 && MB_CUR_MAX < 4)
		e->unicode_error = 1;
	if (e->nbr > 1114111)
		e->unicode_error = 1;
	if (e->nbr <= 255 && e->unicode_error)
	{
		e->unicode_error = 0;
		char_conversion(e);
		return (1);
	}
	if (e->unicode_error == 1)
		return (1);
	return (0);
}

static void		unicode_conversion(t_env *e)
{
	if (e->nbr <= 127)
		char_conversion(e);
	else if (e->nbr <= 2047)
	{
		put_char_to_buf((e->nbr >> 6 & 31) + 192 & 2047, e);
		put_char_to_buf((e->nbr & 63) + 128 & 2047, e);
	}
	else if (e->nbr <= 65535)
	{
		put_char_to_buf((e->nbr >> 12 & 15) + 224 & 65535, e);
		put_char_to_buf((e->nbr >> 6 & 63) + 128 & 65535, e);
		put_char_to_buf((e->nbr & 63) + 128 & 65535, e);
	}
	else if (e->nbr <= 1114111)
	{
		put_char_to_buf((e->nbr >> 18 & 7) + 240 & 1114111, e);
		put_char_to_buf((e->nbr >> 12 & 63) + 128 & 1114111, e);
		put_char_to_buf((e->nbr >> 6 & 63) + 128 & 1114111, e);
		put_char_to_buf((e->nbr & 63) + 128 & 1114111, e);
	}
}

void			char_conversion(t_env *e)
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

void			unicode_conversion_setup(t_env *e)
{
	if (get_unicode_error(e) == 1)
		return ;
	set_unicode_offset(e);
	if (!e->minus && e->nbr > 127)
		put_offset_to_buf(e);
	unicode_conversion(e);
	if (e->minus && e->nbr > 127)
		put_offset_to_buf(e);
}
