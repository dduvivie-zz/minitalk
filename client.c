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
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			return (0);
		i++;
	}
	return (1);
}

/*
Send the length of the string to the server, bit-by-bit.
(an integer is 32 bits)
*/
void	send_length_to_server(int pid, char *str, int len)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len = len >> 1;
		i++;
	}

}


int main(int argc, char** argv)
{
	int		pid;
	int		len;
	char	*str;

	if (!(input_is_correct(argc, argv)))
		return (-1);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(str);
	send_length_to_server(pid, str, len);
	//kill(pid, SIGUSR1);
	return (0);
}