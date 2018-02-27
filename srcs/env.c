/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:59:45 by aledru            #+#    #+#             */
/*   Updated: 2018/02/27 11:01:25 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_env	*create_env(char *str)
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		malloc_error();
	e->buf = "";
	e->str = str;
	e->i = 0;
	return (e);
}

void	resign_offset_precision(t_env *e)
{
	if (e->offset > 0 && e->minus_offset_precision == 1)
	{
		e->offset = -e->offset;
		e->minus_offset_precision = 0;
	}
	if (e->precision > 0 && e->minus_offset_precision == 1)
	{
		e->precision = -e->precision;
		e->minus_offset_precision = 0;
	}
}

void	get_offset(int init_index, t_env *e)
{
	char	*num;
	int		i;
	int		max;

	i = 0;
	if (e->str[e->i] == '-')
		e->i++;
	if (e->str[e->i] == '0')
		while (e->str[e->i] == '0')
			e->i++;
	else
	{
		while (ft_isdigit(e->str[e->i]))
			e->i++;
		if (!(num = ft_memalloc(sizeof(char) * e->i - init_index + 1)))
			malloc_error();
		max = e->i;
		e->i = e->i - (e->i - init_index);
		while (e->i < max)
			num[i++] = e->str[e->i++];
		num[i] = '\0';
		e->offset = ft_atoi(num);
	}
	resign_offset_precision(e);
}

void	get_precision(int init_index, t_env *e)
{
	char	*num;
	int		i;
	int		max;

	i = 0;
	if (e->str[e->i] == '.')
		e->i++;
	while (ft_isdigit(e->str[e->i]))
		e->i++;
	if (e->i - init_index == 0)
		return ;
	if (e->str[init_index] == '.')
		init_index++;
	if (!(num = ft_memalloc(sizeof(char) * e->i - init_index + 1)))
		malloc_error();
	max = e->i;
	e->i = e->i - (e->i - init_index);
	while (e->i < max)
		num[i++] = e->str[e->i++];
	num[i] = '\0';
	e->precision = ft_atoi(num);
	if (e->precision == 0)
		e->is_precision_specified = 1;
	resign_offset_precision(e);
}
