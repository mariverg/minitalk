/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft_hex_toupper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:17:43 by mariverg          #+#    #+#             */
/*   Updated: 2024/02/01 12:51:15 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//imprimer %X
static void	ft_putnbr_hex(unsigned long nbr, int *len)
{
	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16, len);
	ft_putchar("0123456789ABCDEF"[nbr % 16]);
	*len += 1;
}

int	ft_prinft_hex_toupper(unsigned int nbr)
{
	int	count;

	count = 0;
	ft_putnbr_hex(nbr, &count);
	return (count);
	if (nbr % 16 < 10)
		ft_putchar(nbr % 16 + '0');
	else
		ft_putchar(nbr % 16 - 10 + 'a');
	return (0);
}
