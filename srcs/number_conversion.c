/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/02/23 19:33:47 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	is_negative(unsigned short int *n, int *is_neg)
{
	(void)n;
	(void)is_neg;
	if (*n < 0)
	{
		printf("yo\n");
		*n = -*n;
		*is_neg = 1;
	}
}

char		*ft_ittoa(unsigned short int n)
{
	int		is_neg;
	int		size;
	char	*s;
	unsigned short int		n_cpy;

	/*if (n == -2147483648)
		return (ft_strdup("-2147483648"));*/
	is_neg = 0;
	size = 1;
	is_negative(&n, &is_neg);
	n_cpy = (unsigned short int)n;
	while (n_cpy /= 10)
		size++;
	if (NULL != (s = ft_strnew(size += is_neg)))
	{
		while (size--)
		{
			s[size] = n % 10 + '0';
			n /= 10;
		}
		if (is_neg)
			s[0] = '-';
		return (s);
	}
	return (NULL);
}




int		get_nb_digit(t_env *e, int base)
{
	int						nb_digit;
	unsigned long long int	nbr_cp;

	nbr_cp = e->nbr;
	nb_digit = 0;
	while (nbr_cp /= base)
		nb_digit++;
	return (nb_digit + 1);
}

void	double_conversion(t_env *e)
{
	int		nb_digit;
	int		cp;

	cp = e->nbr;
	e->base = 10;
	nb_digit = 0;
	while (cp /= e->base)
		nb_digit++;
	nb_digit++;
	if (e->offset > 0)
		put_offset_precision_to_buf(e, nb_digit);
	put_str_to_buf(ft_itoa(e->nbr), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}

void	octal_conversion(t_env *e)
{
	int				nb_digit;

	nb_digit = get_nb_digit(e, 8);
	e->base = 8;
	if (e->offset >= 0)
		put_offset_precision_to_buf(e, nb_digit);
	put_str_to_buf(base_converter(e, 0), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}

void	hexa_conversion(t_env *e, int is_caps)
{
	int				nb_digit;

	nb_digit = get_nb_digit(e, 16);
	e->base = 16;
	if (e->offset >= 0)
		put_offset_precision_to_buf(e, nb_digit);
	if (is_caps == 1)
		put_str_to_buf(base_converter(e, 1), e, nb_digit, "nbr");
	else
		put_str_to_buf(base_converter(e, 0), e, nb_digit, "nbr");
	if (e->offset < 0)
		put_offset_precision_to_buf(e, nb_digit);
}
