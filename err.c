#include "shell.h"

#include "shell.h"

/**
 * __putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int __putchar(char c)
{
	return (write(2, &c, 1));
}


/**
 * __puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
int __puts(const char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		__putchar(str[i]);
	return (i);
}
