#include "main.h"

/**
 * is_printable - determines if a char is printable or not
 *
 * @c: the char to be checked if printable
 *
 * Return: success
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - a funct to append ascci in hex
 *
 * @buffer: an array of chars
 *
 * @i: Index where appending begins
 *
 * @ascii_code: the assci code
 *
 * Return: success
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
/*recall ++ means increase by +1*/
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a char is a digit
 *
 * @c: Char to be evaluated by the funct above
 *
 * Return: success
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - a funct that casts a number to the specified size
 *
 * @num: number to cast
 *
 * @size: type of number to cast
 *
 * Return: success
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - a funct that casts a number to the specified size
 *
 * @num: number to cast
 *
 * @size: type of number to cast
 *
 * Return: success
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
