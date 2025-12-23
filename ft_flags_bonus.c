/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:52:35 by sarfreit          #+#    #+#             */
/*   Updated: 2025/11/24 20:52:35 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bonus.h"

// Check if it has flags

t_flags	ft_parse_flags(const char *format, int *i)
{
	t_flags	flags;

	flags.has_plus = 0;
	flags.has_space = 0;
	flags.has_hash = 0;
	if (!format)
		return (flags);
	while ((format[*i] == '+') || (format[*i] == ' ') || (format[*i] == '#'))
	{
		if (format[*i] == '+')
			flags.has_plus = 1;
		if (format[*i] == ' ')
			flags.has_space = 1;
		if (format[*i] == '#')
			flags.has_hash = 1;
		(*i)++;
	}
	return (flags);
}

// count flags len for %d and %i

int	ft_apply_di_flags(int nbr, t_flags flags)
{
	if (nbr >= 0)
	{
		if (flags.has_plus == 1)
		{
			ft_putchar_fd('+', 1);
			return (1);
		}
		if (flags.has_space == 1)
		{
			ft_putchar_fd(' ', 1);
			return (1);
		}
	}
	return (0);
}

// count flags len for %x and %X

int	ft_apply_x_flags(unsigned int nbr, t_flags flags, char type)
{
	if ((nbr != 0) && (flags.has_hash == 1))
	{
		if (type == 'x')
			ft_putstr_fd("0x", 1);
		if (type == 'X')
			ft_putstr_fd("0X", 1);
		return (2);
	}
	return (0);
}

// To prevent Handle conversion being more than 25 lines. 
// This sums the len of types %d, %i, %X and %x with flags

int	ft_counter_with_flags(va_list args, t_flags flags, char type)
{
	int				n_di;
	int				len;
	unsigned int	n_x;

	len = 0;
	if ((type == 'd' || (type == 'i')))
	{
		n_di = va_arg(args, int);
		len += (ft_apply_di_flags(n_di, flags)
				+ ft_print_base(n_di));
	}
	else if ((type == 'x') || (type == 'X'))
	{
		n_x = va_arg(args, unsigned int);
		len += (ft_apply_x_flags(n_x, flags, type)
				+ ft_puthex_unsigned(n_x, type));
	}
	return (len);
}
