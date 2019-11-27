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
 * @s1: first string
 * @s2: second string
 * Return: pointer
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int i, j, k, l;
	char *s1_s2;
	char *name = getenv("_");

	if (s1 == NULL)
		i = 0;
	else
	{
		for (i = 0; s1[i]; i++)
			;
	}
	if (s2 == NULL)
		j = 0;
	else
	{
		for (j = 0; s2[j]; j++)
			;
	}
	k = i + j + 1;
	s1_s2 = malloc(k * sizeof(char));
	if (s1_s2 == NULL)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	for (l = 0; l < i; l++)
		s1_s2[l] = s1[l];
	for (l = 0; l < j; l++)
		s1_s2[l + i] = s2[l];
	s1_s2[i + j] = '\0';
	return (s1_s2);
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
