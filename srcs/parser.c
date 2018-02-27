/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:03:30 by aledru            #+#    #+#             */
/*   Updated: 2018/02/27 11:24:31 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_char(t_env *e, char c)
{
	int	count;

	count = 0;
	while (e->str[e->i] == c)
	{
		e->space++;
		e->i++;
		count++;
	}
	return (count);
}

int		is_char_a_converter_or_flag(t_env *e, char c)
{
	if (c == '\0')
		return (0);
	if (c == ' ')
	{
		e->i++;
		fill_char(e, ' ');
		c = e->str[e->i];
		e->i--;
	}
	if (c == 'd' || c == 'x' || c == 'X' || c == 'o' || c == 'c' ||
			c == 'j' || c == 'z' || c == 'l' || c == 'h')
		return (1);
	return (0);
}

char	next_char(t_env *e, char c)
{
	int i;

	i = e->i;
	while (e->str[i] == c)
		i++;
	return (e->str[i]);
}

void	parse_after_percent(t_env *e, va_list arg)
{
	fill_char(e, ' ');
	if (e->str[e->i] == '-' && next_char(e, '-') == '#' && fill_char(e, '-'))
		e->minus_offset_precision = 1;
	if (fill_char(e, '#'))
		e->sharp = 1;
	fill_char(e, ' ');
	while (e->str[e->i] == '+')
	{
		if (is_char_a_converter_or_flag(e, e->str[e->i + 1]))
			e->plus = 1;
		e->i++;
	}
	fill_char(e, ' ');
	while (e->str[e->i] == '-' && is_char_a_converter_or_flag(e,
				e->str[e->i + 1]))
	{
		e->minus = 1;
		e->i++;
	}
	fill_char(e, ' ');
	get_offset(e->i, e);
	get_precision(e->i, e);
	fill_char(e, ' ');
	select_conversion(e, arg);
}
