/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:39:44 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:29:28 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function locates the first occurrence of the null-terminated string needle
in the string haystack, where not more than len characters are searched.
Characters that appear after a `\0' character are not searched.

Return: 1, haystack if needle is an empty string
		2, NULL if needle occurs nowhere in haystack
		3, a pointer to the first char of the first occurence of needle 
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_h;
	char	*ptr_n;
	size_t	len_n;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) == 0)
		return (0);
	len_n = ft_strlen(needle);
	while (len-- >= len_n && ft_strlen(haystack) >= len_n)
	{
		if (*haystack == *needle)
		{
			ptr_h = (char *)haystack;
			ptr_n = (char *)needle;
			while (*ptr_n && *ptr_h++ == *ptr_n)
				ptr_n++;
			if (!*ptr_n)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
