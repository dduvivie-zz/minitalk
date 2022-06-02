/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:46:43 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:26:42 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Compares the two strings 's1' and 's2'. 

Return:	1 if s1 > s2
		0 if s1 == s2
		-1 if s1 > s2
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n > 1 && (*s1 && *s2) && ((unsigned char)*s1 == (unsigned char)*s2))
	{
		s1++;
		s2++;
		n--;
	}
	if ((unsigned char)*s1 > (unsigned char)*s2)
		return (1);
	else if ((unsigned char)*s1 == (unsigned char)*s2)
		return (0);
	else
		return (-1);
}
