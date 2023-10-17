#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags,
int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int handle_write_char(char c, char buffer[], int flags,
int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
int width, int precision, int size);
int is_printable(char);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif

