/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:37:52 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:46:07 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the first occurrence of 'c' (converted to an unsigned char)
in string 's'.

Return: a pointer to the byte located,
		or NULL if no such byte exists within 'n' bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n && (unsigned char)*str != (unsigned char)c)
	{
		str++;
		n--;
	}
	if (n == 0)
		return (NULL);
	return ((void *)str);
}
