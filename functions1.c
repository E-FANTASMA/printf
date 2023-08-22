#include "main.h"

/******Print Unsigned Number**********/
/**
 * print_unsigned - prints an unsigned int
 *
 * @types: form of arguments
 *
 * @buffer: a buffer arra
 *
 * @flags: calculates only all active flags
 *
 * @width: width specifier
 *
 * @precision: specifies precision
 *
 * @size: specifies size
 *
 * Return: len of chars printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';
	/* -- removes 1 from value*/
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***Print unsigned Number in Octal**********/
/**
 * print_octal - Prints an unsigned number in octal notation
 *
 * @types: form of arguments
 *
 * @buffer: a buffer arra
 *
 * @flags: calculates only all active flags
 *
 * @width: width specifier
 *
 * @precision: specifies precision
 *
 * @size: specifies size
 *
 * Return: len of chars printed.
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/********Print Unsigned Number in Hexadecimal*****/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 *
 * @types: form of arguments
 *
 * @buffer: a buffer arra
 *
 * @flags: calculates only all active flags
 *
 * @width: width specifier
 *
 * @precision: specifies precision
 *
 * @size: specifies size
 *
 * Return: len of chars printed.
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/***Print Unsigned Number Upper Hexadecimal*******/
/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal
 *
 * @types: form of arguments
 *
 * @buffer: a buffer arra
 *
 * @flags: calculates only all active flags
 *
 * @width: width specifier
 *
 * @precision: specifies precision
 *
 * @size: specifies size
 *
 * Return: len of chars printed.
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/***Print Hexadecimal Num in Lower or Upper*******/
/**
 * print_hexa - print a hexadecimal number in lower or upper
 *
 * @types: form of arguments
 *
 * @buffer: a buffer arra
 *
 * @map_to: locates in the code
 *
 * @flag_ch: this is the flag_ch comment
 *
 * @flags: calculates only all active flags
 *
 * @width: width specifier
 *
 * @precision: specifies precision
 *
 * @size: specifies size
 *
 * Return: len of chars printed.
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
