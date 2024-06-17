/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:42:19 by mariverg          #+#    #+#             */
/*   Updated: 2024/02/01 12:51:48 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//imprimir %u
int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
	{
		count += ft_putnbr_unsigned(nbr / 10);
		if (count == -1)
			return (-1);
		nbr = nbr % 10;
	}
	if (nbr <= 9)
	{
		if (ft_putchar('0' + nbr) != 1)
			return (-1);
		count++;
	}
	return (count);
}
