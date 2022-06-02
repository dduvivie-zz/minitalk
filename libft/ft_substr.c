/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:25:33 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:19:40 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function get the minimum length we need to allocate memory. 
*/
static int	get_len(char const *s, unsigned int start, size_t len)
{
	int	m_len;

	m_len = 0;
	if (start >= ft_strlen(s))
		return (0);
	while (len-- && s[start])
	{
		m_len++;
		start++;
	}
	return (m_len);
}

/*
This function allocates (with malloc) and returns a substring from the string s.
The substring begins at index ’start’ and has maximum size ’len’.

Parameters: 1. The string from which to create the substring.
			2. The start index of the substring in the string ’s’.
			3. The maximum length of the substring.
Return:		The substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		m_len;

	if (!s)
		return (NULL);
	m_len = get_len(s, start, len);
	str = malloc(m_len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && m_len)
	{
		str[i] = s[start];
		i++;
		start++;
		m_len--;
	}
	str[i] = '\0';
	return (str);
}
