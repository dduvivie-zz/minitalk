/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:01:31 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:11:16 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Find the first occurrence of the character 'c' in the string 's'.

Return: NULL if the character is not found.
		Otherwise, a pointer to the terminator (also if 'c' is specified as '\0')
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (!*s && (char)c != '\0')
		return (NULL);
	return ((char *)s);
}
