#include "shell.h"

/**
 * _strdup - returns pointer to new mem alloc space which contains copy
 * @str: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *str)
{
		char *cpy;

		int len, i;
		char *name = getenv("_");

	if (str == 0)
		return (NULL);

	for (len = 0; str[len]; len++)
		;
	cpy = malloc((len + 1) * sizeof(char));
	if (cpy == NULL)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i <= len; i++)
		cpy[i] = str[i];

	return (cpy);
}


/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: outputs the difference of s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (s1[i] - s2[i]);
}

/**
 * str_concat - concatenates two strings
 * @strc1: first string
 * @strc2: second string
 * Return: pointer
 */
char *str_concat(char *strc1, char *strc2)
{
	char *newstring;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
	if (strc1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}
	newlen = len1 + len2 + 2;
	newstring = malloc(newlen * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		newstring[i] = strc1[i];
	newstring[i] = '/';
	for (j = 0; j < len2; j++)
		newstring[i + 1 + j] = strc2[j];
	newstring[len1 + len2 + 1] = '\0';
	return (newstring);
}



/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int length;

	length = 0;
	for (length = 0; str[length]; length++)
		;
	return (length);
}
