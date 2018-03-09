/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 05:40:02 by aledru            #+#    #+#             */
/*   Updated: 2018/03/09 22:36:19 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void			*ft_memset(void *str, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strcpy (char *dest, const char *src);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);

#endif
