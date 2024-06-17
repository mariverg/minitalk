/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:44:04 by mariverg          #+#    #+#             */
/*   Updated: 2024/02/01 13:03:47 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//imprimir %p
static void	ft_putnbr_hex(unsigned long nbr, int *len)
{
	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16, len);
	ft_putchar("0123456789abcdef"[nbr % 16]);
	*len += 1;
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	nbr;

	write(1, "0x", 2);
	count = 2;
	nbr = (unsigned long)ptr;
	if (!nbr)
	{
		ft_putchar('0');
		count++;
	}
	else
		ft_putnbr_hex(nbr, &count);
	return (count);
}
