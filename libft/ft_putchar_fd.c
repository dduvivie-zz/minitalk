/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:16:56 by dduvivie          #+#    #+#             */
/*   Updated: 2021/11/15 17:48:33 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the character ’c’ to the given file descriptor.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
