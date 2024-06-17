/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:02:06 by mariverg          #+#    #+#             */
/*   Updated: 2024/06/17 14:25:38 by mariverg         ###   ########.fr       */
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

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_count = 0;

	(void)context;
	current_char = (current_char << 1) | (signal == SIGUSR1);
	bit_count++;
	kill(info->si_pid, signal);
	if (bit_count == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	print_intro(getpid());
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
