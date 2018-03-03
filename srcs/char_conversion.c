/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:34:56 by aledru            #+#    #+#             */
/*   Updated: 2018/03/03 17:57:11 by aledru           ###   ########.fr       */
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
