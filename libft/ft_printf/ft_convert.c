/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:39:56 by dduvivie          #+#    #+#             */
/*   Updated: 2022/03/07 13:39:59 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Recursion function which:
	divide the first argument with the base_num(16, 8, etc) till
	the quotient will be 0. Then start to write the remainder of each division.
*/
int	*ft_convert(unsigned long long num, char *base, int base_num, int *len)
{
	unsigned long long	quotient;

	quotient = num / base_num;
	if (quotient == 0)
	{
		if (num < 0)
		{
			*len += ft_print_char('-');
			*len += ft_print_char(base[-num % base_num]);
		}
		else
			*len += ft_print_char(base[num % base_num]);
	}
	else
	{
		ft_convert(quotient, base, base_num, len);
		if (num < 0)
			*len += ft_print_char(base[-num % base_num]);
		else
			*len += ft_print_char(base[num % base_num]);
	}
	return (len);
}
