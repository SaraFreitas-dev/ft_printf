/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:45:55 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/13 17:45:55 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_bonus.h"

void	print_test(const char *format, int expected, int actual)
{
	printf("\nFormat: \"%s\"\n", format);
	printf("  -> EXPECTED LENGTH: %d\n", expected);
	printf("  -> ACTUAL LENGTH:   %d\n", actual);
	if (expected != actual)
		printf("  -> [FAILURE: LENGTH MISMATCH!]\n");
	else
		printf("  -> [SUCCESS]\n");
}

int	main(void)
{
	int		expected_len;
	int		actual_len;
	int		d_pos = 123;
	int		d_neg = -123;
	int		x_val = 510;
	int		x_zero = 0;

	// Constant Format Strings
	const char *format_plus = "Test Plus: Pos: %+d, Neg: %+i, Zero: %+d\n";
	const char *format_space = "Test Space: Pos: % i, Neg: % d, Zero: % i\n";
	// The original printf call must use a format without redundant flags to avoid -Werror
	const char *format_plus_space_orig = "Test Plus/Space: Pos: %+d, Neg: %+i\n"; 
	// The ft_printf call uses the redundant flags to test precedence
	const char *format_plus_space_ft = "Test Plus/Space: Pos: % +d, Neg: % +i\n"; 
	const char *format_hash = "Test Hash: Lower: %#x, Upper: %#X\n";
	const char *format_hash_zero = "Test Hash Zero: Lower: %#x, Upper: %#X\n";

	// --- Flag '+' for %d/%i ---
	printf("\nORIGINAL: ");
	expected_len = printf(format_plus, d_pos, d_neg, x_zero);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format_plus, d_pos, d_neg, x_zero);
	print_test(format_plus, expected_len, actual_len);

	// --- Flag ' ' (Space) for %d/%i ---
	printf("\nORIGINAL: ");
	expected_len = printf(format_space, d_pos, d_neg, x_zero);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format_space, d_pos, d_neg, x_zero);
	print_test(format_space, expected_len, actual_len);

	// --- Case: '+' and ' ' together (Plus takes precedence) ---
	printf("\nORIGINAL: ");
	expected_len = printf(format_plus_space_orig, d_pos, d_neg); 
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format_plus_space_ft, d_pos, d_neg);
	print_test("Pos: % +d (Plus takes precedence)", expected_len, actual_len);

	// --- Flag '#' for %x and %X (Non-Zero) ---
	printf("\nORIGINAL: ");
	expected_len = printf(format_hash, x_val, x_val);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format_hash, x_val, x_val);
	print_test(format_hash, expected_len, actual_len);

	// --- Flag '#' for %x and %X (Zero) ---
	printf("\nORIGINAL: ");
	expected_len = printf(format_hash_zero, x_zero, x_zero);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format_hash_zero, x_zero, x_zero);
	print_test(format_hash_zero, expected_len, actual_len);

	return (0);
}