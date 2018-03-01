/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:03:30 by aledru            #+#    #+#             */
/*   Updated: 2018/03/01 19:48:55 by aledru           ###   ########.fr       */
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

int		is_not_a_converter(char c)
{
	if (c == 'd' || c == 'x' || c == 'X' || c == 'o' || c == 'c' ||
		c == 'j' || c == 'z' || c == 'l' || c == 'h' || c == 'u' || c == 's')
		return (0);
	return (1);
}
void	parse_after_percent(t_env *e, va_list arg)
{
	reset_var(e);
	while (!ft_isdigit(e->str[e->i]) && is_not_a_converter(e->str[e->i])
			&& e->str[e->i + 1])
	{
		if (e->str[e->i] == '-')
			e->minus = 1;
		if (e->str[e->i] == '+')
			e->plus = 1;
		if (e->str[e->i] == '#')
			e->sharp = 1;
		if (e->str[e->i] == ' ')
			e->space = 1;
		if (e->str[e->i] == '.')
		{
			e->dot = 1;
			e->is_precision_specified = 1;
		}
		e->i++;
	}
	if (!e->dot)
		get_offset(e->i, e);
	get_precision(e->i, e);
	select_conversion(e, arg);
}
