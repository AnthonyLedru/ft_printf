/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:31:59 by aledru            #+#    #+#             */
/*   Updated: 2018/03/02 15:26:53 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char_to_buf(char c, t_env *e)
{
	char	*str_c;

	if (!(str_c = ft_memalloc(sizeof(char) * 2)))
		malloc_error();
	str_c[0] = c;
	str_c[1] = '\0';
	e->buf = ft_strjoin(e->buf, str_c);
}

void	put_str_to_buf(char *str, t_env *e)
{
	e->buf = ft_strjoin(e->buf, str);
}

void	put_zero_to_buf(t_env *e)
{
	char	*zero;

	if (e->offset > 0)
	{
		if (!(zero = ft_memalloc(sizeof(char) * e->offset + 1)))
			malloc_error();
		ft_memset(zero, '0', e->offset);
		e->buf = ft_strjoin(e->buf, zero);
	}
	e->offset = 0;
}

void	put_offset_to_buf(t_env *e)
{
	char	*offset;

	if (e->offset > 0)
	{
		if (!(offset = ft_memalloc(sizeof(char) * e->offset + 1)))
			malloc_error();
		if (e->zero == 1)
			ft_memset(offset, '0', e->offset);
		else
			ft_memset(offset, ' ', e->offset);
		e->buf = ft_strjoin(e->buf, offset);
	}
}

void	put_precision_to_buf(t_env *e, int arg_size)
{
	char	*prec;

	if (e->precision > arg_size)
	{
		if (!(prec = ft_memalloc(sizeof(char) * e->precision - arg_size + 1)))
			malloc_error();
		ft_memset(prec, '0', e->precision - arg_size);
		prec[e->precision - arg_size] = '\0';
		e->buf = ft_strjoin(e->buf, prec);
	}
}
