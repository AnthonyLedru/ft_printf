/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:34:56 by aledru            #+#    #+#             */
/*   Updated: 2018/02/28 17:21:48 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_conversion(t_env *e)
{
	if (!e->nbr)
	{
		if (e->offset > 0)
			put_offset_precision_to_buf(e, 1);
		e->count_before_buf_reset = ft_strlen(e->buf) + 1;
		e->buf = ft_strjoin(e->buf, "\0");
		write(1, e->buf, ft_strlen(e->buf) + 1);
		ft_memdel((void*)&e->buf);
		e->buf = ft_memalloc(sizeof(char));
	}
	if (e->offset > 0)
		put_offset_precision_to_buf(e, 1);
	put_char_to_buf(e->nbr, e);
	if (e->offset < 0)
		put_offset_precision_to_buf(e, 1);
}
