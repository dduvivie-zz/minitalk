/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:53:01 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:34:24 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Tests for a decimal digit character,  '0' ~ '9'.
Return: 1(True) or 0(False)
*/
int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}
