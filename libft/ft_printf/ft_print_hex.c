/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:04:01 by dduvivie          #+#    #+#             */
/*   Updated: 2022/03/07 14:04:04 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Recieve the unsigned int argument, 
	and pass to ft_convert function as a unsigned long long value
*/
int	ft_print_hex(unsigned int i, char *base)
{
	int					len;
	int					base_num;
	unsigned long long	num;

	len = 0;
	base_num = 16;
	num = (unsigned long long)i;
	ft_convert(num, base, base_num, &len);
	return (len);
}
