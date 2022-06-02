/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:40:20 by dduvivie          #+#    #+#             */
/*   Updated: 2022/03/07 13:40:23 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_int(int i);
int		ft_print_uint(unsigned int i);
int		ft_print_hex(unsigned int i, char *base);
int		ft_print_point(unsigned long long p);
int		*ft_convert(unsigned long long num, char *base, int base_num, int *len);

#endif
