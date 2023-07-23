#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @b: take a parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *b)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *b + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_j] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*b = curr_j - 1;

	return (flags);
}
