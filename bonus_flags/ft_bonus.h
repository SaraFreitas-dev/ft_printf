/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:31:46 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/13 02:33:51 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include "ft_printf.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	has_plus;
	int	has_space;
	int	has_hash;
}	t_flags;

t_flags	ft_parse_flags(const char *format, int *i);
int		ft_apply_di_flags(int nbr, t_flags flags);
int		ft_apply_x_flags(unsigned int nbr, t_flags flags, char type);
int		ft_counter_with_flags(va_list args, t_flags flags, char type);

#endif