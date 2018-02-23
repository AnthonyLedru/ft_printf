/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:25:18 by aledru            #+#    #+#             */
/*   Updated: 2018/02/23 17:40:33 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*base_converter(t_env *e, int is_caps)
{
	int				nb_digit;
	char			*res;
	int				char_ref;

	char_ref = is_caps == 1 ? 55 : 87;
	nb_digit = get_nb_digit(e, e->base);
	if (!(res = (char*)malloc(sizeof(char) * nb_digit + 1)))
		return (NULL);
	res[nb_digit--] = '\0';
	while (nb_digit >= 0)
	{
		if ((e->nbr % e->base >= 10 || e->nbr % e->base <= 15))
			res[nb_digit] = char_ref + (e->nbr % e->base);
		if (e->nbr % e->base < 10)
			res[nb_digit] = e->nbr % e->base + '0';
		e->nbr /= e->base;
		nb_digit--;
	}
	return (res);
}
