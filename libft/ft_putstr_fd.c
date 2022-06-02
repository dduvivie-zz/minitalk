/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:41:46 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:06:47 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the string ’s’ to the given file descriptor.
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, sizeof(char) * len);
}
