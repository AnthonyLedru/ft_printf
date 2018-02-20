/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:20:52 by aledru            #+#    #+#             */
/*   Updated: 2018/02/20 14:07:33 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_digit(int value, int base, int neg)
{
	int nb_digit;

	nb_digit = 0;
	while (value / base)
	{
		value = value / base;
		nb_digit++;
	}
	if (neg == 1 && base == 10)
		nb_digit++;
	return (nb_digit);
}

void	fill_tab(char *res, int value, int base, int nb_digit)
{
	while (nb_digit >= 0)
	{
		if (value % base >= 10 || value % base <= 15)
			res[nb_digit] = 55 + (value % base);
		if (value % base < 10)
			res[nb_digit] = value % base + '0';
		value = value / base;
		nb_digit--;
	}
}

char	*ft_itoa_base(int value, int base)
{
	int		nb_digit;
	char	*res;
	int		neg;

	neg = 0;
	if (base > 16 || base < 2)
		return (NULL);
	if (value == -2147483648)
		return ("-2147483648\0");
	if (value < 0)
	{
		value = value * -1;
		neg = 1;
	}
	nb_digit = count_digit(value, base, neg);
	if (!(res = (char*)malloc(sizeof(char) * nb_digit + 2)))
		return (NULL);
	fill_tab(res, value, base, nb_digit);
	if (neg == 1 && base == 10)
		res[0] = '-';
	return (res);
}
