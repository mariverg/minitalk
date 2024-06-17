/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:19:39 by mariverg          #+#    #+#             */
/*   Updated: 2024/06/13 12:52:48 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_intro(int pid)
{
	ft_printf("\n\033[1;32m");
	ft_printf("███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n");
	ft_printf("██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n");
	ft_printf("███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n");
	ft_printf("╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
	ft_printf("███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n");
	ft_printf("╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");
	ft_printf("Process ID: \033[1;34m%d\033[1;37m\t", pid);
	ft_printf("\n\n\033[0m");
}

void	handle_bit_signal(int signal)
{
	static unsigned char	current_character;
	static int				bit_count;

	if (signal == SIGUSR1)
		current_character = current_character | 1;
	else if (signal == SIGUSR2)
		current_character = current_character | 0;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_character);
		bit_count = 0;
		current_character = 0;
	}
	else
		current_character = current_character << 1;
}

int	main(void)
{
	print_intro(getpid());
	signal(SIGUSR1, handle_bit_signal);
	signal(SIGUSR2, handle_bit_signal);
	while (1)
		pause();
	return (0);
}
