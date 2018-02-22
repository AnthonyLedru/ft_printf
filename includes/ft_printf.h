/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:16:54 by aledru            #+#    #+#             */
/*   Updated: 2018/02/22 21:17:01 by aledru           ###   ########.fr       */
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

typedef struct	s_type
{
	unsigned int	ui;
	unsigned int	ui_cpy;
	unsigned long	ul;
	unsigned long	ul_cpy;
	unsigned long long	ll;
	unsigned long long	ll_cpy;
	unsigned short int	uh;
	unsigned short int	uh_cpy;
	unsigned char	hh;
	unsigned char	hh_cpy;
	uintmax_t	uj;
	uintmax_t	uj_cpy;


}				t_type;

typedef struct	s_env
{
	char			*buf;
	char			*str;
	int				i;
	int				count;
	int				offset;
	int				precision;
	int				is_precision_specified;
	struct s_type	*type;
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
void	init_type_cpy(t_env *e);

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
** -------------------------- Number Conversion --------------------------------
*/

void	double_conversion(t_env *e, va_list arg);
void	hexa_conversion(t_env *e, va_list arg, int is_caps, char *type);
int		get_nb_digit(t_env *e, char *type, int base);

/*
** --------------------------- Base Converter ----------------------------------
*/

char	*base_converter(t_env *e, int base, int is_caps, char *type);

/*
** -------------------------------- Flag ---------------------------------------
*/

void	select_conversion_uint(t_env *e, va_list arg);
void	select_conversion_long(t_env *e, va_list arg);
void	select_conversion_short(t_env *e, va_list arg);

#endif
