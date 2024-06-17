/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:11:17 by mariverg          #+#    #+#             */
/*   Updated: 2024/02/01 13:17:12 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	typevalues(char format, va_list arg)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'x')
		return (ft_prinft_hex_tolower(va_arg(arg, unsigned int)));
	else if (format == 'X')
		return (ft_prinft_hex_toupper(va_arg(arg, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	va_start(arg, format);
	if (write(1, "", 0) == -1)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			len += typevalues(*format, arg);
			format++;
		}
		else
		{
			len += ft_putchar(*format);
			format++;
		}
	}
	va_end(arg);
	return (len);
}

/* int main()
{
	ft_printf("%cs%cs%c", 'c', 'b', 'a');
	return (0);
}  */