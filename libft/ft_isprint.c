/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:56:51 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:34:44 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Tests for any printing character, including space (` ').
The value of the argument must be representable as an unsigned char or
the value of EOF.
Return: 1(True) or 0(False)
*/
int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}
