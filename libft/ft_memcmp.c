/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:09:32 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:54:15 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares byte string 's1' against byte string 's2'.
Both strings are assumed to be 'n' bytes long.

Return: 0 if the two string are identical.
		Otherwise, the difference between the first two differing bytes (treated as
     	unsigned char values)
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 1 && (unsigned char)*str1 == (unsigned char)*str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
