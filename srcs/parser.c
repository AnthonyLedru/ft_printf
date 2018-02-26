/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:03:30 by aledru            #+#    #+#             */
/*   Updated: 2018/02/26 14:15:04 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_char_a_converter_or_flag(char c)
{
	if (c == '\0')
		return (0);
	if (c == 'd' || c == 'x' || c == 'X' || c == 'o' || c == 'c' ||
			c == 'j' || c == 'z' || c == 'l' || c == 'h' || c == 'u')
		return (1);
	return (0);
}

void	fill_space(t_env *e)
{
	while (e->str[e->i] == ' ')
		e->i++;
}

void	parse_after_percent(t_env *e, va_list arg)
{
	fill_space(e);
	while (e->str[e->i] == '#')
	{
		e->sharp = 1;
		e->i++;
	}
	fill_space(e);
	while (e->str[e->i] == '+' && !ft_isdigit(e->str[e->i + 1]))
	{
		e->plus = 1;
		e->i++;
	}
	fill_space(e);
	while (e->str[e->i] == '-' && !ft_isdigit(e->str[e->i + 1]))
	{
		e->minus = 1;
		e->i++;
	}
	fill_space(e);
	get_offset(e->i, e);
	get_precision(e->i, e);
	fill_space(e);
	select_conversion(e, arg);
}
