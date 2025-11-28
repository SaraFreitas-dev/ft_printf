/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:49:58 by sarfreit          #+#    #+#             */
/*   Updated: 2025/11/17 22:49:58 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	has_plus;
	int	has_space;
	int	has_hash;
}	t_flags;

int		ft_print_str(char *str);
int		ft_puthex_unsigned(unsigned long nbr, char type);
int		ft_print_ptr(void *ptr);
int		ft_print_base(int nbr);
int		ft_print_base_unsigned(unsigned int nbr);
int		ft_print_c(int c);
int		ft_handle_conversion(char type, va_list args, t_flags flags);
int		ft_printf(const char *format, ...);

// Flags Bonus
t_flags	ft_parse_flags(const char *format, int *i);
int		ft_apply_di_flags(int nbr, t_flags flags);
int		ft_apply_x_flags(unsigned int nbr, t_flags flags, char type);
int		ft_counter_with_flags(va_list args, t_flags flags, char type);

#endif