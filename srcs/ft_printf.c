/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:46:07 by aledru            #+#    #+#             */
/*   Updated: 2018/02/14 19:25:19 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list arg;
	va_start(arg, str);
	char *s = va_arg(arg, char *);
	s = va_arg(arg, char *);
	(void)s;
	va_end(arg);
	return (0);
}
