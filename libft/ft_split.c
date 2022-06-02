/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:13:55 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/18 13:31:29 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Counts the total number of words in 's'.
*/
static int	count_words(char const *s, char c)
{
	int	words;
	int	i;
	int	word_len;

	words = 0;
	i = 0;
	word_len = 0;
	while (s[i])
	{
		if (s[i] != c)
			word_len++;
		else
		{
			if (word_len)
			{
				words++;
				word_len = 0;
			}
		}
		i++;
	}
	if (word_len)
		words++;
	return (words);
}

/*
Free all memories allocated with malloc before.
*/
static void	split_free(char **t, int elem)
{
	int	i;

	i = 0;
	while (i < elem)
	{
		free(t[i]);
		i++;
	}
	free(t);
}

/*
Get one word in 's', and call split_free when an allocation error occured.
*/
static char	*get_str(const char *s, char c, char **t, int elem)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		split_free(t, elem);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
Get the next delimiter or the end of string.
*/
static char	*get_next_delimiter(char const *s, char c)
{
	while (*s != c && *s)
		s++;
	return ((char *)s);
}

/*
Allocates (with malloc) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter.
The array must be ended by a NULL pointer.

Parameters: 1. The string to be split
			2. The delimiter character
Return:		The array of new strings resulting from the split.
			NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c)
{
	int		i;
	char	**t;

	if (!s)
		return (0);
	t = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!t)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			t[i] = get_str(s, c, t, i);
			if (!t[i])
				return (0);
			s = get_next_delimiter(s, c);
			i++;
		}
	}
	t[i] = 0;
	return (t);
}
