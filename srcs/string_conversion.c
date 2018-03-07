/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:02:46 by aledru            #+#    #+#             */
/*   Updated: 2018/03/07 20:24:17 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_conversion(t_env *e, va_list arg)
{
	char	*next_arg;
	int		arg_size;
	char	*precise_str;

	next_arg = va_arg(arg, char *);
	if (!next_arg)
		next_arg = "(null)";
	arg_size = ft_strlen(next_arg);
	if (e->precision < arg_size && e->is_precision_specified == 1)
	{
		e->offset -= e->precision;
		if (!(precise_str = ft_memalloc(sizeof(char) * e->precision + 1)))
			malloc_error();
		ft_memcpy(precise_str, next_arg, e->precision);
	}
	else
	{
		e->offset -= arg_size;
		precise_str = next_arg;
	}
	if (!e->minus)
		put_offset_to_buf(e);
	put_str_to_buf(precise_str, e);
	if (e->minus)
		put_offset_to_buf(e);
}

int				get_unicode_s_error(t_env *e)
{
	if ((e->nbr >= 55296 && e->nbr <= 57343))
		e->unicode_error = 1;
	if ((e->nbr > 255 && e->nbr <= 2047) && MB_CUR_MAX < 2)
		e->unicode_error = 1;
	if (e->nbr > 2047 && e->nbr <= 65535 && MB_CUR_MAX < 3)
		e->unicode_error = 1;
	if (e->nbr > 65535 && e->nbr <= 1114111 && MB_CUR_MAX < 4)
		e->unicode_error = 1;
	if (e->nbr > 1114111)
		e->unicode_error = 1;
	if (e->unicode_error == 1)
		return (1);
	return (0);
}

int				get_string_unicode_error(t_env *e, wchar_t *next_arg)
{
	int error;
	int	i;
	int	size;

	i = 0;
	error = 0;
	size = 0;
	while (next_arg[i])
	{
		size += get_unicode_size(next_arg[i]);
		e->nbr = next_arg[i];
		if (get_unicode_s_error(e) == 1)
		{
			if (!(e->precision && e->is_precision_specified
						&& e->precision < size))
				return (1);
		}
		i++;
	}
	return (0);
}

int		get_number_of_unicode_to_display(t_env *e, wchar_t *next_arg)
{
	int size;
	int nb_unicode;

	if (!next_arg)
		return (0);
	nb_unicode = 0;
	size = 0;
	while (*next_arg)
	{
		size += get_unicode_size(*next_arg);
		if ((e->precision == 0 && e->is_precision_specified == 0) ||
				e->precision >= size)
		{
			e->offset -= get_unicode_size(*next_arg);
			nb_unicode++;
		}
		else
			break ;
		next_arg++;
	}
	return (nb_unicode);
}

void	string_unicode_conversion(t_env *e, va_list arg)
{
	wchar_t *next_arg;
	char	*null_str;
	int		nb_unicode_to_display;
	int		i;

	i = 0;
	null_str = NULL;
	next_arg = va_arg(arg, wchar_t*);
	nb_unicode_to_display = get_number_of_unicode_to_display(e, next_arg);
	if (!next_arg)
		null_str = "(null)";
	else if (get_string_unicode_error(e, next_arg) == 1)
		return ;
	if (!e->minus)
		put_offset_to_buf(e);
	if (null_str)
		put_str_to_buf(null_str, e);
	else
		while (i < nb_unicode_to_display)
		{
			e->nbr = next_arg[i];
			if (e->nbr <= 255 && MB_CUR_MAX < 2)
			{
				e->unicode_error = 0;
				char_conversion(e);
			}
			else
				unicode_conversion(e);
			i++;
		}
	if (e->minus)
		put_offset_to_buf(e);
}
