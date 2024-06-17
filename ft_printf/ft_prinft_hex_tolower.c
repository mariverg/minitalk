/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft_hex_tolower.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:29:03 by mariverg          #+#    #+#             */
/*   Updated: 2024/02/01 12:51:08 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//imprimir %x
static void	ft_putnbr_hex(unsigned long nbr, int *len)
{
	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16, len);
	ft_putchar("0123456789abcdef"[nbr % 16]);
	*len += 1;
}

int	ft_prinft_hex_tolower(unsigned int nbr)
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
