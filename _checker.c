#include "main.h"

/**
 * is_digit - Checks if a char is a digit
 * @c: evaluated char
 * Return: 1 if digit, otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - A number is cast to the provided size
 * @num: The number that will be casted
 * @size: the type to be casted is indicated by a number
 * Return: number's cast value
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

