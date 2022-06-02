/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:42:20 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:14:38 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates sufficient memory for a copy of the string 's1',
does the copy, and returns a pointer to it.
*/
char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
	{
		return (0);
	}
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
