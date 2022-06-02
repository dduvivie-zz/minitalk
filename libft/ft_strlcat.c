/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:39:30 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/18 13:53:27 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Get the length of string which will be returned in 'ft_strlcat'.
*/
static int	get_len(char *dst, const char *src, size_t dstsize)
{
	int	len;

	if ((int)dstsize >= 0 && (int)dstsize <= (int)ft_strlen(dst))
		len = ft_strlen(src) + (int)dstsize;
	else
		len = ft_strlen(src) + ft_strlen(dst);
	return (len);
}

/*
Appends string 'src' to the end of 'dst'.
It will append at most 'dstsize' - 1 characters.
It will then NUL-terminate, unless 'dstsize' is 0 or
the original 'dst' string was longer than 'dstsize'.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	len;

	len = get_len(dst, src, dstsize);
	if (dstsize <= ft_strlen(dst) + 1)
		return (len);
	while (*dst)
	{
		dstsize--;
		dst++;
	}
	while (dstsize > 1 && *src)
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	*dst = '\0';
	return (len);
}
