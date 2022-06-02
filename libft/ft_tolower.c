/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:32:23 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:19:19 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Converts an upper-case letter to the corresponding lower-case letter.
The argument must be representable as an unsigned char.
*/
int	ft_tolower(int c)
{
	if (ft_isalpha(c) && (c > 64 && c < 91))
		c += 32;
	return (c);
}
