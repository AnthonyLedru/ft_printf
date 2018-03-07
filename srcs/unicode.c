/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:16:58 by aledru            #+#    #+#             */
/*   Updated: 2018/03/07 18:13:30 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_unicode_size(wchar_t unicode)
{
	if (unicode <= 255)
		return (1);
	else if (unicode <= 2047)
		return (2);
	else if (unicode <= 65535)
		return (3);
	else if (unicode <= 1114111)
		return (4);
	return (0);
}

void			unicode_conversion(t_env *e)
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
