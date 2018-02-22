/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:59:45 by aledru            #+#    #+#             */
/*   Updated: 2018/02/22 21:21:34 by aledru           ###   ########.fr       */
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
	e->count = 0;
	if (!(e->type = ft_memalloc(sizeof(t_type))))
		malloc_error();
	return (e);
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
	if (e->i - init_index <= 1)
		return ;
	if (e->str[init_index] == '.')
		init_index++;
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
	e->precision = ft_atoi(num);
	if (e->precision == 0)
		e->is_precision_specified = 1;
}

void	init_type_cpy(t_env *e)
{
	e->type->ui_cpy = e->type->ui;
	e->type->ul_cpy = e->type->ul;
	e->type->ll_cpy = e->type->ll;
	e->type->uh_cpy = e->type->uh;
	e->type->hh_cpy = e->type->hh;
	e->type->uj_cpy = e->type->uj;
}
