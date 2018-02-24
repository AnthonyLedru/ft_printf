/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:00:19 by aledru            #+#    #+#             */
/*   Updated: 2018/02/24 13:49:05 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_negative(intmax_t *n, int *is_neg)
{
	if (*n < 0)
	{
		*n = -*n;
		*is_neg = 1;
	}
}

char	*ft_ittoa(t_env *e)
{
	int			is_neg;
	int			size;
	char		*s;
	intmax_t	n_cpy;

	if ((unsigned long)e->nbr == -9223372036854775808U)
		return ("-9223372036854775808");
	size = 1;
	is_neg = 0;
	is_negative(&e->nbr, &is_neg);
	n_cpy = e->nbr;
	while (n_cpy /= 10)
		size++;
	if (NULL != (s = ft_strnew(size += is_neg)))
	{
		while (size--)
		{
			s[size] = e->nbr % 10 + '0';
			e->nbr /= 10;
		}
		if (is_neg)
			s[0] = '-';
		return (s);
	}
	return (NULL);
}

int		get_nb_digit(t_env *e, int base)
{
	int			nb_digit;
	intmax_t	nbr_cp;

	nbr_cp = e->nbr;
	nb_digit = 0;
	while (nbr_cp /= base)
		nb_digit++;
	return (nb_digit + 1);
}

void	double_conversion(t_env *e)
{
	int		nb_digit;
	long long int		cp;

	cp = e->nbr;
	e->base = 10;
	nb_digit = 0;
	while (cp /= e->base)
		nb_digit++;
	nb_digit++;
	if (e->offset > 0)
		put_offset_precision_to_buf(e, nb_digit);
	put_str_to_buf(ft_ittoa(e), e, nb_digit, "nbr");
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
