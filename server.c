/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:43:30 by dduvivie          #+#    #+#             */
/*   Updated: 2022/06/02 17:43:33 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
This recursive function calculate 2 to the n-th power.
*/
int	power_calculator(int base, int exponents)
{
	if (exponents != 0)
		return (base * power_calculator(base, exponents - 1));
	else
		return (1);
}

/*
Corrects all 32 bits received from the clients, to get the length value
*/
void	convert_bit_to_int(int sig, int *received_len, int *len, char **str)
{
	static int	bit_count = 0;
	char 		*ptr;

	if (sig == SIGUSR1)
		*len += power_calculator(2, bit_count);
	bit_count++;
	if (bit_count == 32)
	{
		*received_len = 1;
		bit_count = 0;
		ptr = NULL;
		ptr = (char *)malloc( ((int)*len + 1) * sizeof(char));
		if (!ptr)
			return ;
		*str = ptr;
	}
}

/*
Corrects 8 bits for one char, then assign the character in string
*/
void	convert_bit_to_char(int sig, int *len, char **str)
{
	static int				bit_count = 0;
	static int				i = 0;
	static unsigned char	char_bits = 0;
	
	if (sig == SIGUSR1)
		char_bits += (char)power_calculator(2, bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		(*str)[i] = char_bits;
		char_bits = 0;
		bit_count = 0;
		i++;
		*len -= 1;
	}
	if (*len == 0)
	{
		(*str)[i] = '\0';
		i = 0;
	}
}

/*
This function wil be called every time when the client programm send signal.
The signal SIGUSR1 represent 1, and SIGUSR2 represent 0.
*/
void	get_info_from_client(int signal)
{
	static int	received_len = 0;
	static int	len = 0;
	static char	*str = NULL;
	
	if (!received_len)
		convert_bit_to_int(signal, &received_len, &len, &str);
	else
	{
		convert_bit_to_char(signal, &len, &str);
		if (len == 0)
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			received_len = 0;
		}
	}
}


int main(void)
{
	int					pid;
	struct sigaction	act;
	
	pid = (int)getpid();
	ft_printf("PID : %d\n", pid);
	act.sa_handler = get_info_from_client;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while(1)
		usleep(100);
	return(0);
}