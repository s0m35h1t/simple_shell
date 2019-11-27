#include "shell.h"

/* Function Declarations for builtin shell commands: */
int cd(char **args);
int help(char **args);
int exitshell(char **args);
int history(char **args);
int b_setenv(char **args);
int b_unsetenv(char **args);

/* List of builtin commands, followed by their corresponding functions. */
char *builtin_str[] = {
"cd",
"help",
"exit",
"alias",
"env",
"history",
"setenv",
"unsetenv"};

int (*builtin_func[])(char **) = {
&cd,
&help,
&exitshell,
&alias,
&env,
&history,
&b_setenv,
&b_unsetenv};

char *builtins_help[] = {
"Change the shell working directory.\nUSAGE : cd PATH\n",
"USAGE: help bultin\n   Display information about builtin commands\n",
"exit: exit [n]\n   Exit the shell. ",
"alias: alias [name[=value] ... ]\n   Define or display aliases.\n",
"env: prints the current environment\n",
"history : Display the history list",
"USAGE: setenv NAME VALUE\n   Initialize a new environment variable, or modify an existing one\n",
"USAGE: unsetenv NAME\n   Remove an environment variable"};
/**
* num_builtins - number of builtins
*
* Return: void
*/
int num_builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}

/*Builtin function implementations.*/

/**
* env - env builtin
* @args: argument list
* Return: int
*/
int env(char **args __attribute__((unused)))
{
int i;

for (i = 0; environ[i]; i++)
{
_puts(environ[i]);
_puts("\n");
}
return (1);
}


/**
* b_setenv - unsetenv builtin
* @args: array of arguments
* Return: 1 or error
*/
int b_setenv(char **args)
{
int i = 0, j;
char *variale;
char *pname = _getenv("_");

if (!args[1] && !args[2])
{
perror(pname);
return (1);
}
else
{
variale = str_concat(args[1], "=");
variale = str_concat(variale, args[2]);
}

while (environ[i])
{
j = 0;
while (args[1][j] == environ[i][j])
j++;
if (environ[i][j] == '=')
{
environ[i] = variale;
return (1);
}
i++;
}
environ[i] = variale;
environ[i + 1] = NULL;
return (1);
}
/**
* b_unsetenv - unsetenv builtin
* @args: array of arguments
* Return: 1 or error
*/
int b_unsetenv(char **args)
{
int i = 0, j;
char *name = _getenv("_");

if (args[1] == NULL)
{
perror(name);
return (1);
}

while (environ[i])
{
j = 0;
while (args[1][j] == environ[i][j])
j++;
if (environ[i][j] == '=')
{

while (environ[i] != NULL)
{
environ[i] = environ[i + 1];
i++;
}
environ[i - 1] = NULL;
break;
}
i++;
}

return (1);
}
/**
* cd - cd builtins
* @args: array of arguments
* Return: 1 or error
*/
int cd(char **args)
{
char PWD[BUFSIZE];
char oPWD[BUFSIZE];
char *dir;
char *name = getenv("");

if (getcwd(oPWD, sizeof(oPWD)) == NULL)
perror(name);

if (args[1])
{
if (_strcmp(args[1], "~") == 0)
dir = strdup(_getenv("HOME"));
else if (_strcmp(args[1], "-") == 0)
dir = strdup(_getenv("OLDPWD"));
else
dir = args[1];
}
else
dir = strdup(_getenv("HOME"));

_setenv("OLDPWD", oPWD, 1);
if (chdir(dir) != 0)
perror(name);

if (getcwd(PWD, sizeof(PWD)) == NULL)
perror(name);
_setenv("PWD", PWD, 1);
return (1);
}

/**
* alias - alias builtins
* @args: array of arguments
* Return: 1 or error
*/
int alias(char **args)
{
int i, j = 0;
char *name;
char *value;
alias_t alias;

if (!args[1])
{
for (i = 0; aliass[i].name; i++)
{
printf("%s='%s'\n", aliass[i].name, aliass[i].value);
}
}
else
{
for (j = 1; args[j]; j++)
{
name = strtok(args[j], "='");
alias.name = strdup(name);
value = strtok(NULL, "='");
alias.value = strdup(value);

for (i = 0; aliass[i].name; i++)
{
if (strcmp(aliass[i].name, name) == 0)
break;
}
aliass[i] = alias;
if (i == alicount)
{
alicount++;
}
}
}

return (1);
}
