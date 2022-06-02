/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:28:45 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 18:06:14 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = (n % 10) + '0';
		write(fd, &c, 1);
	}
}
