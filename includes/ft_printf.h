/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:16:54 by aledru            #+#    #+#             */
/*   Updated: 2018/02/23 16:29:10 by aledru           ###   ########.fr       */
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


typedef struct s_flag
{
	int i;
	int	ui;
	int ul;
	int ll;
	int uh;
	int hh;
	int uj;
}				t_flag;

typedef struct	s_env
{
	char			*buf;
	char			*str;
	int				i;
	unsigned long long nbr;
	int				offset;
	int				precision;
	int				is_precision_specified;
	int				base;
	int				undefined_char_count;
	struct s_flag	*flag;
}				t_env;

/*
** ------------------------------- ft_printf -----------------------------------
*/

int		ft_printf(const char *str, ...);

/*
** ---------------------------------- Env --------------------------------------
*/

t_env	*create_env(char *str);
void	get_offset(int init_index, t_env *e);
void	get_precision(int init_index, t_env *e);

/*
** --------------------------------- Error -------------------------------------
*/

void	malloc_error(void);
void	arg_error(void);

/*
** ---------------------------------- Put --------------------------------------
*/

void	put_char_to_buf(char c, t_env *e);
void	put_str_to_buf(char *str, t_env *e, int size, char *type);
void	put_nbr_to_buf(int nbr, t_env *e);
void	put_offset_precision_to_buf(t_env *e, int arg_size);

/*
** -------------------------- Conversion Selector ------------------------------
*/

void	parse_after_percent(t_env *e, va_list arg);
void	select_conversion(t_env *e, va_list arg);

/*
** -------------------------- String Conversion --------------------------------
*/

void	string_conversion(t_env *e, va_list arg);

/*
** --------------------------- Char Conversion ---------------------------------
*/

void	char_conversion(t_env *e, va_list arg);

/*
** -------------------------- Number Conversion --------------------------------
*/

int		get_nb_digit(t_env *e, int base);
void	double_conversion(t_env *e);
void	octal_conversion(t_env *e);
void	hexa_conversion(t_env *e, int is_caps);

/*
** --------------------------- Base Converter ----------------------------------
*/

char	*base_converter(t_env *e, int is_caps);

/*
** -------------------------------- Flag ---------------------------------------
*/

void	select_conversion_flag(t_env *e, va_list arg);

#endif
