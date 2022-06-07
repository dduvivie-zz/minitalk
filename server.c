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

static void	info_from_client(int signal)
{
	if(signal == SIGUSR1)
		ft_printf("SIGUSR1\n");
	else if(signal == SIGUSR2)
		ft_printf("SIGUSR2\n");
	return ;
}


int main(void)
{
	int					pid;
	struct sigaction	act;
	
	pid = (int)getpid();
	ft_printf("PID : %d\n", pid);
	act.sa_handler = info_from_client;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while(1)
		usleep(100);
	return(0);
}