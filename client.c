/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:20:40 by mariverg          #+#    #+#             */
/*   Updated: 2024/06/17 12:50:47 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsignal(unsigned char character, pid_t pid)
{
	int	bit_position;

	bit_position = 7;
	while (bit_position >= 0)
	{
		if ((character & (1 << bit_position)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
		bit_position--;
	}
	return ;
}

int	main(int argc, const char *argv[])
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc > 3)
		return (0);
	while (argv[2][i] != '\0')
	{
		sendsignal(argv[2][i], pid);
		i++;
	}
	sendsignal('\0', pid);
	return (0);
}
