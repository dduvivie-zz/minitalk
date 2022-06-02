/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:55:13 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:19:56 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Check if the character passed as parameter can be found in 'set'.
Parameters: 1. The character to be checked.
			2. The reference set of characters to trim.
Return:		i if the character fined in 'set', 0 if not so.
*/
static int	find_char(char c, char const *set)
{
	int	flag;
	int	set_i;

	flag = 0;
	set_i = 0;
	while (!flag && set[set_i])
	{
		if (c == set[set_i])
			flag = 1;
		set_i++;
	}
	return (flag);
}

/*
Get the length to allocate memory.

Parameters: 1. The string to be trimmed.
			2. The reference set of characters to trim.
Return:		The length.
*/
static int	get_len(char const *s1, char const *set)
{
	int	len;
	int	start_i;
	int	last_i;

	len = ft_strlen(s1);
	if (len == 0)
		return (0);
	start_i = 0;
	last_i = len - 1;
	while (s1[start_i] && find_char(s1[start_i], set))
	{
		len--;
		start_i++;
	}
	while (last_i > start_i && find_char(s1[last_i], set))
	{
		len--;
		last_i--;
	}
	return (len);
}

/*
Allocates (with malloc) and returns a copy of ’s1’ 
with the characters specified in ’set’ removed from the beginning
and the end of the string.

Parameters: 1. The string to be trimmed.
			2. The reference set of characters to trim.
Return:		The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start_i;
	int		last_i;

	if (!s1 || !set)
		return (0);
	str = malloc((get_len(s1, set) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	start_i = 0;
	last_i = ft_strlen(s1) - 1;
	while (s1[start_i] && find_char(s1[start_i], set))
		start_i++;
	while (last_i > start_i && find_char(s1[last_i], set))
		last_i--;
	while (start_i <= last_i)
	{
		str[i] = s1[start_i];
		i++;
		start_i++;
	}
	str[i] = '\0';
	return (str);
}
