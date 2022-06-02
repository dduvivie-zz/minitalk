/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:40:06 by dduvivie          #+#    #+#             */
/*   Updated: 2022/03/07 13:40:08 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Function to check the format
%c  -> write a character
%s  -> write a character array
%p  -> the void * pointer argument is printed in hexadecimal
%d  -> convert int argument to signed decimal notation 
%i  -> same as %d
%u  -> convert unsigned int argument to unsigned decimal notation
%x  -> convert unsigned int argument to unsigned hexadecimal notation (abcdef)
%X  -> same as %x but (ABCDEF)
%%  -> '%' is written
*/
static int	check_format(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_point((unsigned long long)va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_print_int(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_print_char(str[i]);
		else
		{
			len += check_format(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
