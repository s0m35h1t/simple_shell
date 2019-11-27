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
/**
* _setenv - get  variable
* @name: variable name
* @value: valiable value
* @overwrite: overwited or no
* Return: 0 or 1
*/
int _setenv(char *name, char *value, int overwrite)
{
int i = 0, j = 0;
char *token;

token = _strdup(name);
token = str_concat(token, "=");
token = str_concat(token, value);

while (environ[i])
{
j = 0;
while (name[j] == environ[i][j])
j++;
if (!name[j])
{
if (overwrite)
{
environ[i] = token;
return (1);
}
}
i++;
}
return (0);
}
