#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @b: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int curr_b;
	int wj = 0;

	for (curr_b = *i + 1; format[curr_b] != '\0'; curr_b++)
	{
		if (is_digit(format[curr_b]))
		{
			wj *= 10;
			wj += format[curr_b] - '0';
		}
		else if (format[curr_b] == '*')
		{
			curr_b++;
			wj = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_b - 1;

	return (wj);
}
