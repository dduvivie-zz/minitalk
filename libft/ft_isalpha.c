/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:52:22 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:27:22 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Tests for any character for which isupper(3) or islower(3) is true.
The value of the argument must be representable as an unsigned char or
the value of EOF.
Return: 1(True) or 0(False)
*/
int	ft_isalpha(int c)
{
	if (c < 65 || ((c > 90) && (c < 97)) || c > 122)
		return (0);
	return (1);
}
