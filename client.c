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
#include <stdio.h>


int main(int argc, char** argv)
{
	pid_t pid;
	if (argc < 3)
		ft_printf("Wrong input.\n");
	else
	{
		// check that pid corresponded to the process
		pid = (int)argv[1];
		kill(pid, SIGUSR1);
	}
	return (0);
}