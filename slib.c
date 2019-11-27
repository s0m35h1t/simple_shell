#include "shell.h"

/**
 * _realloc - realloc more memoiry
 * @p: pointer to realloced
 * @size: size to add
 * Return: value of integer
 */
char **_realloc(char **p, size_t *size)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*size) + 10));
	if (new == NULL)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
		new[i] = p[i];
	*size += 10;
	free(p);
	return (new);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: value of integer
 */

int _atoi(char *s)
{
	int i, n, signe = 1;

	i = n = 0;
	while ((*(s + i) < '0' || *(s + i) > '9') && (*(s + i) != '\0'))
	{
		if (*(s + i) == '-')
			signe *= -1;
		i++;
	}
	while ((*(s + i) >= '0') && (*(s + i) <= '9'))
	{
		n = n * 10 + signe * (*(s + i) - '0');
		i++;
	}
	return (n);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
int _puts(const char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}
