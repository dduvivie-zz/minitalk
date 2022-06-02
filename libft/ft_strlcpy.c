/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:25:06 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/18 13:55:35 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies up to 'dstsize' - 1 characters from the string 'src' to 'dst',
NUL-terminating the result if 'dstsize' is not 0.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (dstsize > 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (len);
}
