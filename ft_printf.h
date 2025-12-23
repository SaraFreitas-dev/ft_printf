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

int		ft_print_str(char *str);
int		ft_puthex_unsigned(unsigned long nbr, char type);
int		ft_print_ptr(void *ptr);
int		ft_print_base(int nbr);
int		ft_print_base_unsigned(unsigned int nbr);
int		ft_print_c(int c);
int		ft_printf(const char *format, ...);

#endif