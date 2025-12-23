/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 03:36:37 by sarfreit          #+#    #+#             */
/*   Updated: 2025/11/16 03:36:37 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %s: Format as a null-terminated string.
int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

// %x, %X (type): Convert to hexadecimal and print it
int	ft_puthex_unsigned(unsigned long nbr, char type)
{
	int		len;
	char	hex;

	len = 0;
	if ((nbr >= 16))
		len += ft_puthex_unsigned(nbr / 16, type);
	hex = "0123456789abcdef"[nbr % 16];
	if ((type == 'X') && ((hex >= 'a') && (hex <= 'f')))
		hex -= 32;
	ft_putchar_fd(hex, 1);
	len++;
	return (len);
}

// %p: The void * pointer argument has to be printed in hexadecimal format
int	ft_print_ptr(void *ptr)
{
	int					len;
	unsigned long int	hex;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	hex = (long unsigned int)ptr;
	ft_putstr_fd("0x", 1);
	len = 2;
	len += ft_puthex_unsigned(hex, 'p');
	return (len);
}

//%d %i (type): Print nbr in base 10 (numbers with signs)
int	ft_print_base(int nbr)
{
	int			len;
	long int	num;

	len = 0;
	num = nbr;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		len += 1;
	}
	if (num >= 10)
		len += ft_print_base(num / 10);
	ft_putnbr_fd((num % 10), 1);
	len++;
	return (len);
}

// %u: Print an unsigned decimal in base 10
int	ft_print_base_unsigned(unsigned int nbr)
{
	int				len;

	len = 0;
	if (nbr >= 10)
		len += ft_print_base_unsigned(nbr / 10);
	ft_putnbr_fd((nbr % 10), 1);
	len++;
	return (len);
}
