/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 03:20:08 by sarfreit          #+#    #+#             */
/*   Updated: 2025/11/16 03:20:08 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_handle_conversion(char type, va_list args, t_flags flags)
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
		len += ft_counter_with_flags(args, flags, type);
	else if (type == 'u')
		len += ft_print_base_unsigned(va_arg(args, unsigned int));
	else if ((type == 'x') || (type == 'X'))
		len += ft_counter_with_flags(args, flags, type);
	else if (type == '%')
		len += ft_print_c('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	int		i;
	va_list	args;
	t_flags	flags;

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
			flags = ft_parse_flags(format, &i);
			counter += ft_handle_conversion(format[i], args, flags);
		}
		else
			counter += ft_print_c(format[i]);
		i++;
	}
	va_end(args);
	return (counter);
}

/*
int	main(void)
{
	char c = 'a';
	char *s = "string";

	int n = 123;
	ft_printf("%x\n", -2);

	ft_printf("c: %c,\n normal text,\ns: %s, \np: %p,\n", c, s, s);
	ft_printf("d: %d, \ni: %i, \nu: %u\n", n, n, n);
	ft_printf("x: %x, \nX: %X, \n", n, n);
	ft_printf("Percentage sign: %%\n");

	// FLAGS
	int nbr = +123;
	ft_printf("Has_plus \nd: %+d\n", nbr);
	ft_printf("Has_space \ni: % i\n", nbr);
	ft_printf("Has plus and space, so space is ignored: % +d\n", nbr);
	ft_printf("Has_hash \nx: %#x \nX: %#X\n", nbr, nbr);

	return (0);
}
*/