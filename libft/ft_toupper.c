/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:32:03 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:18:33 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Converts a lower-case letter to the corresponding upper-case letter. 
The argument must be representable as an unsigned char.
*/
int	ft_toupper(int c)
{
	if (ft_isalpha(c) && (c > 96 && c < 123))
		c -= 32;
	return (c);
}
