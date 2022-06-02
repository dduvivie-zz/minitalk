/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:02:42 by dduvivie          #+#    #+#             */
/*   Updated: 2022/03/07 14:02:43 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Produce output "(null)" and return this length
*/
static int	ft_print_null(void)
{
	char	*s;

	s = ft_strdup("(null)");
	write(1, s, 6);
	free(s);
	return (6);
}

/*
	Treat string
	If the string is NULL, call the function "ft_print_null"
*/
int	ft_print_str(char *s)
{
	int	len;

	if (!s)
		return (ft_print_null());
	len = ft_strlen(s);
	write(1, s, sizeof(char) * len);
	return (len);
}
