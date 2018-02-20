/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:16:54 by aledru            #+#    #+#             */
/*   Updated: 2018/02/20 14:20:09 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>


/* TO DELETE */

#include <stdio.h>

/*
** --------------------------------- Struct ------------------------------------
*/

typedef struct	s_env
{
	char	*str;
	int		i;
	int		count;
}				t_env;

/*
** ------------------------------- ft_printf -----------------------------------
*/

int		ft_printf(const char *str, ...);

/*
** ---------------------------------- Env --------------------------------------
*/

t_env	*create_env(char *str);

/*
** --------------------------------- Error -------------------------------------
*/

void	malloc_error(void);
void	arg_error(void);

/*
** ---------------------------------- Put --------------------------------------
*/

void	ft_putchar_count(char c, t_env *e);
void	ft_putstr_count(char *str, t_env *e);
void	ft_putnbr_count(int nbr, t_env *e);
void	ft_putoffset_count(int offset, t_env *e);

/*
** -------------------------- Conversion Selector ------------------------------
*/

void	check_conversion(t_env *e, va_list arg);

/*
** -------------------------- String Conversion --------------------------------
*/

void	string_conversion(t_env *e, va_list arg);

/*
** -------------------------- Number Conversion --------------------------------
*/

void	double_conversion(t_env *e, va_list arg);
void	hexa_conversion(t_env *e, va_list arg);

#endif
