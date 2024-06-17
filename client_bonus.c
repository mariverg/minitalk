/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:03:32 by mariverg          #+#    #+#             */
/*   Updated: 2024/06/17 14:27:16 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	unsigned char	bit;

	bit = (unsigned char)signal;
	if (bit == SIGUSR1)
		ft_printf("1");
	else if (bit == SIGUSR2)
	{
		ft_printf("0");
		ft_printf("\nMassage has been successfully received!\n");
	}
	usleep(100);
}

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

int	main(int argc, char const *argv[])
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
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
