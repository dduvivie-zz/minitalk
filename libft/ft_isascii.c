/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:54:32 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:29:03 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Tests for an ASCII character, which is any character
between 0 and 127.
Return: 1(True) or 0(False)
*/
int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
