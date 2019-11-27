#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments list
 * Return: 0
 **/
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
char *buffer;
char *name = getenv("_");
buffer = malloc(BUFSIZE);
if (buffer == NULL)
{
perror(name);
exit(EXIT_FAILURE);
}

shell_loop();

free(buffer);
return (EXIT_SUCCESS);
}
