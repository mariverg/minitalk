/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:34:52 by mariverg          #+#    #+#             */
/*   Updated: 2024/02/01 12:52:07 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// para imprimir el %d o %i
static int	ft_putnbr_aux(int nb)
{
	(void)nb;
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (ft_putnbr_aux(nb));
	if (nb < 0)
	{
		if (ft_putchar('-'))
			nb = -nb;
		count++;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		if (count == -1)
			return (-1);
		nb = nb % 10;
	}
	if (nb <= 9)
	{
		if (ft_putchar('0' + nb) != 1)
			return (-1);
		count++;
	}
	return (count);
}
/* int main()
{
	int str = 15829;
	ft_printf(" numero es :%d", str);
	return (0); */
// }