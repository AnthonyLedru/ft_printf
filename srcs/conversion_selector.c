/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:49:55 by aledru            #+#    #+#             */
/*   Updated: 2018/02/20 15:06:06 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_space(t_env *e)
{
	while (e->str[e->i] == ' ')
		e->i++;
}

int		get_offset(int init_index, t_env *e)
{
	char	*num;
	int		i;
	int max;

	i = 0;
	if (e->str[e->i] == '-')
		e->i++;
	while (ft_isdigit(e->str[e->i]))
		e->i++;
	if (!(num = ft_memalloc(sizeof(char) * e->i - init_index + 1)))
		malloc_error();
	max = e->i;
	e->i = e->i - (e->i - init_index);
	while (e->i < max)
	{
		num[i] = e->str[e->i];
		e->i++;
		i++;
	}
	num[i] = '\0';
	return (ft_atoi(num));
}

void	check_conversion(t_env *e, va_list arg)
{
	int offset;

	fill_space(e);
	offset = get_offset(e->i, e);
	if (offset > 0)
		ft_putoffset_count(offset, e);
	fill_space(e);
	if (e->str[e->i] == '%')
		ft_putchar_count('%', e);
	if (e->str[e->i] == 's')
		string_conversion(e, arg);
	if (e->str[e->i] == 'd')
		double_conversion(e, arg);
	if (e->str[e->i] == 'X')
		hexa_conversion(e, arg);
	if (offset < 0)
		ft_putoffset_count(offset, e);
}
