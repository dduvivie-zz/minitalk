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


void	my_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("PASS\n");
}

int main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	// wait till the client file receive input from the command line
	signal(SIGUSR1, my_handler);
	pause();
	return(0);
}