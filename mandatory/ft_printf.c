/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 02:34:46 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/13 02:34:46 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_handle_conversion(char type, va_list args)
{
	int				len;

	len = 0;
	if (type == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (type == 'p')
		len += ft_print_ptr(va_arg(args, void *));
	else if ((type == 'd') || (type == 'i'))
		len += ft_print_base(va_arg(args, int));
	else if (type == 'u')
		len += ft_print_base_unsigned(va_arg(args, unsigned int));
	else if ((type == 'x') || (type == 'X'))
		len += ft_puthex_unsigned(va_arg(args, unsigned int), type);
	else if (type == '%')
		len += ft_print_c('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	int		i;
	va_list	args;

	counter = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			counter += ft_handle_conversion(format[i], args);
		}
		else
			counter += ft_print_c(format[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
