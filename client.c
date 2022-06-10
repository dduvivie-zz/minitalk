/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:43:08 by dduvivie          #+#    #+#             */
/*   Updated: 2022/06/02 17:43:09 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
Check the command line arguments from user,
return 1 if arguments are corrects, and return 0 if not so.
*/
int	input_is_correct(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Error: Input is incorrect!\n");
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Error: Non valid pid!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/*
Send the length of the string to the server, bit-by-bit.
*/
void	send_length_to_server(int pid, int len)
{
	int	i;

	i = 0;
	while (i++ < 32)
	{
		if (len & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len = len >> 1;
		usleep(100);
	}
}

/*
Send each character of the string to the server, bit-by-bit.
*/
void	send_string_to_server(int pid, int len, char *str)
{
	int				bit_count;
	unsigned char	char_bits;

	bit_count = 0;
	while (len--)
	{
		char_bits = *str;
		while (bit_count++ < 8)
		{
			if (char_bits & 0x01)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			char_bits = char_bits >> 1;
			usleep(100);
		}
		bit_count = 0;
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		len;
	char	*str;

	if (!(input_is_correct(argc, argv)))
		return (-1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(str);
	if (len != 0)
	{
		send_length_to_server(pid, len);
		send_string_to_server(pid, len, str);
	}
	//system("leaks client > client_log");
	//system("leaks server > server_log");
	return (0);
}
