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

//void sighandler(int signum)
//{
//	printf("Caught signal %d, coming out...\n", signum);
//	exit(1);
//}

int	test1(void)
{
	ft_printf("Test for ft_printf\n");
	return (0);
}

int main(void)
{
	test1();
	//signal(SIGINT, sighandler);
	//while(1)
	//{
	//  printf("Going to sleep for a second...\n");
	//  sleep(1); 
	//}
	return(0);
}