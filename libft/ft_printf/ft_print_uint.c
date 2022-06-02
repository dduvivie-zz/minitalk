/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:54:51 by dduvivie          #+#    #+#             */
/*   Updated: 2022/03/07 13:54:54 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Get the length of string to represent the unsigned integer number.
*/
static int	get_len(unsigned int n)
{
	int		len;

	len = 0;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

/*
Allocates (with malloc(3)) and returns a string representing 
the unsigned integer received as an argument.

Parameters: The unsigned integer to convert.
Return:		The string representing the unsigned integer. 
			NULL if the allocation fails.
*/
static char	*ft_utoa(unsigned int n)
{
	int				i;
	char			*str;
	long long int	num;

	i = get_len(n);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	num = (long long int)n;
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

/*
	Treat unsigned int
*/
int	ft_print_uint(unsigned int i)
{
	char	*s;
	int		len;

	s = ft_utoa(i);
	len = ft_print_str(s);
	free(s);
	return (len);
}
