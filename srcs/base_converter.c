/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:25:18 by aledru            #+#    #+#             */
/*   Updated: 2018/02/21 19:13:59 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*base_converter(t_env *e, int base, int is_caps, char *type)
{
	int				nb_digit;
	char			*res;

	nb_digit = get_nb_digit(e, type, base);
	if (!(res = (char*)malloc(sizeof(char) * nb_digit + 1)))
		return (NULL);
	res[nb_digit] = '\0';
	nb_digit--;
	while (nb_digit >= 0)
	{
		if (ft_strcmp(type, "ui") == 0)
		{
			if ((e->type->ui % base >= 10 || e->type->ui % base <= 15) && is_caps == 1)
				res[nb_digit] = 55 + (e->type->ui % base);
			if ((e->type->ui % base >= 10 || e->type->ui % base <= 15) && is_caps == 0)
				res[nb_digit] = 87 + (e->type->ui % base);
			if (e->type->ui % base < 10)
				res[nb_digit] = e->type->ui % base + '0';
			e->type->ui = e->type->ui / base;
		}
		if (ft_strcmp(type, "ul") == 0)
		{
			if ((e->type->ul % base >= 10 || e->type->ul % base <= 15) && is_caps == 1)
				res[nb_digit] = 55 + (e->type->ul % base);
			if ((e->type->ul % base >= 10 || e->type->ul % base <= 15) && is_caps == 0)
				res[nb_digit] = 87 + (e->type->ul % base);
			if (e->type->ul % base < 10)
				res[nb_digit] = e->type->ul % base + '0';
			e->type->ul /= base;
		}
		if (ft_strcmp(type, "ll") == 0)
		{
			if ((e->type->ll % base >= 10 || e->type->ll % base <= 15) && is_caps == 1)
				res[nb_digit] = 55 + (e->type->ll % base);
			if ((e->type->ll % base >= 10 || e->type->ll % base <= 15) && is_caps == 0)
				res[nb_digit] = 87 + (e->type->ll % base);
			if (e->type->ll % base < 10)
				res[nb_digit] = e->type->ll % base + '0';
			e->type->ll /= base;
		}
		if (ft_strcmp(type, "uh") == 0)
		{
			if ((e->type->uh % base >= 10 || e->type->uh % base <= 15) && is_caps == 1)
				res[nb_digit] = 55 + (e->type->uh % base);
			if ((e->type->uh % base >= 10 || e->type->uh % base <= 15) && is_caps == 0)
				res[nb_digit] = 87 + (e->type->uh % base);
			if (e->type->uh % base < 10)
				res[nb_digit] = e->type->uh % base + '0';
			e->type->uh /= base;
		}
		if (ft_strcmp(type, "hh") == 0)
		{
			if ((e->type->hh % base >= 10 || e->type->hh % base <= 15) && is_caps == 1)
				res[nb_digit] = 55 + (e->type->hh % base);
			if ((e->type->hh % base >= 10 || e->type->hh % base <= 15) && is_caps == 0)
				res[nb_digit] = 87 + (e->type->hh % base);
			if (e->type->hh % base < 10)
				res[nb_digit] = e->type->hh % base + '0';
			e->type->hh /= base;
		}
		if (ft_strcmp(type, "uj") == 0)
		{
			if ((e->type->uj % base >= 10 || e->type->uj % base <= 15) && is_caps == 1)
				res[nb_digit] = 55 + (e->type->uj % base);
			if ((e->type->uj % base >= 10 || e->type->uj % base <= 15) && is_caps == 0)
				res[nb_digit] = 87 + (e->type->uj % base);
			if (e->type->uj % base < 10)
				res[nb_digit] = e->type->uj % base + '0';
			e->type->uj /= base;
		}
		nb_digit--;
	}
	return (res);
}
