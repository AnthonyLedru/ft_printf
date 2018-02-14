/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:16:54 by aledru            #+#    #+#             */
/*   Updated: 2018/02/14 19:26:09 by aledru           ###   ########.fr       */
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
	char	*buf;
	int		index;
}				t_env;

/*
** -------------------------------- Fractol ------------------------------------
*/

int		ft_printf(const char *str, ...);

#endif
