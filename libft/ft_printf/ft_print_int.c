/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:52:42 by dduvivie          #+#    #+#             */
/*   Updated: 2022/03/07 13:52:44 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Treat int / decimal number
*/
int	ft_print_int(int i)
{
	char	*s;
	int		len;

	s = ft_itoa(i);
	len = ft_print_str(s);
	free(s);
	return (len);
}
