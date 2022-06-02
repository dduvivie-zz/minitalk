/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:07:15 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:43:41 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Get the length of string to represent the integer number.
*/
static int	get_len(int n)
{
	int		len;
	long	num;

	len = 0;
	num = (long)n;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 9)
	{
		len++;
		num = num / 10;
	}
	len++;
	return (len);
}

/*
Allocates (with malloc(3)) and returns a string representing the integer
received as an argument. Negative numbers must be handled.

Parameters: 1. The integer to convert.
Return:		The string representing the integer. NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	long long int	num;

	str = malloc((get_len(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = get_len(n);
	str[i] = '\0';
	num = (long long int)n;
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	i--;
	while (i > 0 && num > 9)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	str[i] = (num % 10) + '0';
	return (str);
}
