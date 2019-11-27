#include "shell.h"


/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments list
 * Return: 0
 **/
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
FILE *fp;
char *buffer;
int i = 0;
char *name = getenv("_");
history_list = malloc(BUFSIZE * BUFSIZE);
buffer = malloc(BUFSIZE);
aliass = malloc(BUFSIZE * sizeof(alias_t));
if (history_list == NULL || buffer == NULL || aliass == NULL)
{
perror(name);
exit(EXIT_FAILURE);
}
alicount = 0;
fp = fopen(str_concat(getenv("HOME"), "/.simple_shell_history"), "r");
if (fp != NULL)
{
while (fgets(buffer, BUFSIZE, fp) != NULL)
{
history_list[i] = strdup(buffer);
i++;
}
fclose(fp);
}
hiscount = i;
shell_loop();
fp = fopen(str_concat(getenv("HOME"), "/.simple_shell_history"), "a");
if (fp != NULL)
{
for (i = hiscount; history_list[i]; i++)
fprintf(fp, "%s", history_list[i]);
fclose(fp);
}
free(history_list);
free(aliass);
free(buffer);
free(fp);
return (EXIT_SUCCESS);
}
