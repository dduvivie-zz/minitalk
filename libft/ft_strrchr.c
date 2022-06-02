/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:08:02 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/18 13:57:42 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function returns a pointer to the last occurrence of the
character c in the string s.
It returns NULL if the character is not found, and returns a pointer
to the terminator if c is specified as '\0'.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		exist;

	exist = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			exist = 1;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	if (!exist)
		return (NULL);
	while (*s != (char)c)
		s--;
	return ((char *)s);
}
