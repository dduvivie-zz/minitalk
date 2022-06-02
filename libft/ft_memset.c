/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:45:11 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:47:46 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Writes 'len' bytes of value 'c' (converted to an unsigned char)
to the string 'b'.

Return:	its first argument.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len--)
	{
		*str = c;
		str++;
	}
	return (b);
}
