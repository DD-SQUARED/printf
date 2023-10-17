#include "main.h"
/**
 * print_char - A char is printed
 * @types: Lists arguments
 * @buffer: Print handled by the buffer array
 * @flags: The active flags calculated
 * @width: Width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: char number printed
 */
int print_char(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - A string is printed
 * @types: Lists arguments
 * @buffer: Print handled by the buffer array
 * @flags:  The active flags calculated
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: char number printed
 */
int print_string(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - A percentage sign is printed
 * @types: Lists arguments
 * @buffer: Print handled by the buffer array
 * @flags:  The active flags calculated
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: char number printed
 */
int print_percent(va_list types, char buffer[], int flags, int width,
int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

