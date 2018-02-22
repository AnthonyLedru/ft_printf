/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:46:07 by aledru            #+#    #+#             */
/*   Updated: 2018/02/22 16:57:23 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_to_buf_until_percent(t_env *e)
{
	while (e->str[e->i] && e->str[e->i] != '%')
	{
		put_char_to_buf(e->str[e->i], e);
		e->i++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list arg;
	t_env	*e;

	va_start(arg, str);
	e = create_env((char*)str);
	while (e->str[e->i])
	{
		put_to_buf_until_percent(e);
		if (!e->str[e->i] || !e->str[e->i])
			break ;
		e->i++;
		parse_after_percent(e, arg);
		e->i++;
	}
	ft_putstr(e->buf);
	va_end(arg);
	return (ft_strlen(e->buf));
}
