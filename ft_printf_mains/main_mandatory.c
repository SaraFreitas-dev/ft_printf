/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:12:47 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/13 18:12:47 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

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
	void	*ptr_val = &expected_len;
	void	*ptr_null = NULL;
	char	*s_null = NULL;
	
	const char *format1 = "Test c/%%: Char: %c, Percent: %%\n";
	const char *format2 = "Test s: String: %s, NULL: %s\n";
	const char *format3 = "Test p: Pointer: %p, NULL Pointer: %p\n";
	const char *format4 = "Test d/i: Pos: %d, Neg: %i, Max: %d, Min: %i\n";
	const char *format5 = "Test u: Unsigned Max: %u, Zero: %u, Neg as u: %u\n";
	const char *format6 = "Test x/X: Lower: %x, Upper: %X, Zero: %x\n";

	// --- Test %c and %% ---
	printf("\nORIGINAL: ");
	expected_len = printf(format1, 'B');
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format1, 'B');
	print_test(format1, expected_len, actual_len);

	// --- Test %s ---
	printf("\nORIGINAL: ");
	expected_len = printf(format2, "Test String", s_null);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format2, "Test String", s_null);
	print_test(format2, expected_len, actual_len);

	// --- Test %p ---
	printf("\nORIGINAL: ");
	expected_len = printf(format3, ptr_val, ptr_null);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format3, ptr_val, ptr_null);
	print_test(format3, expected_len, actual_len);

	// --- Test %d and %i ---
	printf("\nORIGINAL: ");
	expected_len = printf(format4, 123, -123, INT_MAX, INT_MIN);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format4, 123, -123, INT_MAX, INT_MIN);
	print_test(format4, expected_len, actual_len);

	// --- Test %u ---
	printf("\nORIGINAL: ");
	expected_len = printf(format5, UINT_MAX, 0, -50);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format5, UINT_MAX, 0, -50);
	print_test(format5, expected_len, actual_len);

	// --- Test %x and %X ---
	printf("\nORIGINAL: ");
	expected_len = printf(format6, 255, 255, 0);
	printf("FT_PRINTF: ");
	actual_len = ft_printf(format6, 255, 255, 0);
	print_test(format6, expected_len, actual_len);

	return (0);
}