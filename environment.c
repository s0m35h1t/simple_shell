#include "shell.h"

/**
* _getenv - get  variable
* @name: variable name
* Return: string
*/
char *_getenv(char *name)
{
int i = 0;
char *token;
while (environ[i])
{
token = strtok(_strdup(environ[i]), "=");
if (strcmp(token, name) == 0)
return (strtok(NULL, "="));
i++;
}
return (NULL);
}
