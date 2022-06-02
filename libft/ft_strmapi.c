/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:06:13 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:24:26 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applies the function ’f’ to each character of the string ’s’,
and passing its index as first argument to create a new string (with malloc(3))
resulting from successive applications of ’f’.

Parameters: 1. The string on which to iterate.
			2. The function to apply to each character.
Return:		The string created from the successive applications of ’f’.
			(null) if allocation fails.	
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				i;

	if (!s || !f)
		return (NULL);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
