/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:25:18 by aledru            #+#    #+#             */
/*   Updated: 2018/02/27 11:46:45 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*base_converter_d(t_env *e)
{
	int			is_neg;
	int			size;
	char		*str;

	if ((unsigned long)e->nbr == -9223372036854775808U)
		return ("-9223372036854775808");
	is_neg = 0;
	if ((intmax_t)e->nbr < 0)
	{
		e->nbr = -e->nbr;
		is_neg = 1;
		e->plus = 0;
	}
	size = get_nb_digit(e) + is_neg + e->plus;
	if (!(str = ft_memalloc(sizeof(char) * size)))
		malloc_error();
	while (size--)
	{
		str[size] = e->nbr % 10 + '0';
		e->nbr /= 10;
	}
	str[0] = is_neg ? '-' : str[0];
	str[0] = e->plus ? '+' : str[0];
	return (str);
}

char	*base_converter_o(t_env *e)
{
	int				nb_digit;
	char			*res;
	int				char_ref;
	int				sharp_size;

	sharp_size = e->sharp == 1 && e->nbr != 0 ? 1 : 0;
	char_ref = e->caps == 1 ? 55 : 87;
	nb_digit = get_nb_digit(e);
	if (!(res = (char*)malloc(sizeof(char) * nb_digit + 1 + sharp_size)))
		return (NULL);
	res[nb_digit + sharp_size] = '\0';
	while (--nb_digit + sharp_size >= 0 + sharp_size)
	{
		if ((e->nbr % e->base >= 10 || e->nbr % e->base <= 15))
			res[nb_digit + sharp_size] = char_ref + (e->nbr % e->base);
		if (e->nbr % e->base < 10)
			res[nb_digit + sharp_size] = e->nbr % e->base + '0';
		e->nbr /= e->base;
	}
	if (sharp_size != 0)
		res[0] = '0';
	return (res);
}

char	*base_converter_x(t_env *e)
{
	int				nb_digit;
	char			*res;
	int				char_ref;
	int				sharp_size;

	sharp_size = e->sharp == 2 && e->nbr != 0 ? 2 : 0;
	char_ref = e->caps == 1 ? 55 : 87;
	nb_digit = get_nb_digit(e);
	if (!(res = (char*)malloc(sizeof(char) * nb_digit + 1 + sharp_size)))
		return (NULL);
	res[nb_digit + sharp_size] = '\0';
	while (--nb_digit + sharp_size >= 0 + sharp_size)
	{
		if ((e->nbr % e->base >= 10 || e->nbr % e->base <= 15))
			res[nb_digit + sharp_size] = char_ref + (e->nbr % e->base);
		if (e->nbr % e->base < 10)
			res[nb_digit + sharp_size] = e->nbr % e->base + '0';
		e->nbr /= e->base;
	}
	if (sharp_size != 0)
	{
		res[0] = '0';
		res[1] = e->caps == 1 ? 'X' : 'x';
	}
	return (res);
}
