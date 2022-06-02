/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:28:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/03/07 14:28:47 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Recieve the pointer address as a unsigned long long value, 
	and pass it to "ft_convert" function
*/

int	ft_print_point(unsigned long long p)
{
	int	len;
	int	base_num;

	len = 0;
	base_num = 16;
	len += ft_print_str("0x");
	ft_convert(p, "0123456789abcdef", base_num, &len);
	return (len);
}
