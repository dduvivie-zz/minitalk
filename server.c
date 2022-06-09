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

char	*malloc_str(int len)
{
	char	*ptr;

	//ft_printf("------------------%d----------\n", len);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_printf("OK\n");
	return (ptr);
}

/*
Put each bit recieved from client in the integer variable.
*/
void	convert_bit_to_int(int sig, int *get_len_val, int *len, char **str)
{
	static int	bit_count = 0;

	ft_printf("++++++++++++%d++++++++++++\n", *len);
	if (sig == SIGUSR1)
		*len += 1;
	if (++bit_count < 32)
		*len = *len << 1;
	else
	{
		*get_len_val = 1;
		bit_count = 0;
		//ft_printf("++++++++++++%d++++++++++++\n", *len);
		*str = malloc_str(*len);
	}
}

void	convert_bit_to_char(int sig, int *len, char **str)
{
	static int				bit_count = 0;
	static int				i = 0;
	static unsigned char	char_bits = 0;

	ft_printf("IN  i : %d\n", i);
	if (sig == SIGUSR1)
		char_bits += 1;
	if (++bit_count < 8)
		char_bits = char_bits << 1;
	else
	{
		*str[i] = char_bits;
		char_bits = 0;
		i++;
		*len -= 1;
	}
}

/*
This function wil be called every time when the client programm send signal.
The signal SIGUSR1 represent 1, and SIGUSR2 represent 0.
*/
void	get_info_from_client(int signal)
{
	static int	get_len_val = 0;
	static int	len = 0;
	static char	*str = NULL;
	
	if (!get_len_val)
		convert_bit_to_int(signal, &get_len_val, &len, &str);
	else
	{
		convert_bit_to_char(signal, &len, &str);
		if (len == 0)
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			get_len_val = 0;
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