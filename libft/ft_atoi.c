/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:46:37 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/18 16:09:19 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Converts the initial portion of the string pointed to by
'str' to int representation.
*/
int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					minus;

	num = 0;
	minus = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - 48);
		if (num >= LONG_MAX && minus == 1)
			return (-1);
		if (num > LONG_MAX && minus == -1)
			return (0);
		str++;
	}
	num *= minus;
	return ((int)num);
}
