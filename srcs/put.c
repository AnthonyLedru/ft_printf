/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:31:59 by aledru            #+#    #+#             */
/*   Updated: 2018/02/27 11:52:49 by aledru           ###   ########.fr       */
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

void	put_str_to_buf(char *str, t_env *e, int size, char *type)
{
	char	*precise_str;

	if (ft_strcmp(type, "str") == 0 && e->precision
			< size && e->precision > 0 && e->is_precision_specified == 0)
	{
		precise_str = ft_memalloc(sizeof(char) * e->precision + 1);
		ft_memcpy(precise_str, str, e->precision);
		precise_str[e->precision] = '\0';
	}
	else
		precise_str = ft_strdup(str);
	e->buf = ft_strjoin(e->buf, precise_str);
}

void	put_offset_precision_to_buf(t_env *e, int arg_size)
{
	char	*offset;
	char	*prec;

	if (e->offset < 0)
		e->offset *= -1;
	e->offset -= (e->precision > arg_size && e->offset > e->precision)
		? e->precision : arg_size;
	if (e->sharp > 0)
		e->offset -= e->sharp;
	if (e->offset > 0)
	{
		if (!(offset = ft_memalloc(sizeof(char) * e->offset + 1)))
			malloc_error();
		ft_memset(offset, ' ', e->offset);
		e->buf = ft_strjoin(e->buf, offset);
	}
	if (e->precision > arg_size)
	{
		if (!(prec = ft_memalloc(sizeof(char) * e->precision - arg_size + 1)))
			malloc_error();
		ft_memset(prec, '0', e->precision - arg_size);
		prec[e->precision - arg_size] = '\0';
		if (e->plus)
			e->buf = ft_strjoin(e->buf, "+");
		if (e->plus_before_precision)
			e->buf = ft_strjoin(e->buf, "+");
		e->buf = ft_strjoin(e->buf, prec);
	}
	e->offset = 0;
}
