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
"setenv",
"unsetenv"};

static int (*builtin_func[])(char **) = {
&cd,
&help,
&exitshell,
&alias,
&env,
&b_setenv,
&b_unsetenv};

static char *builtins_help[] = {
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
__puts(pname);
__puts("USAGE: setenv NAME VALUE\n");
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
__puts(name);
__puts("USAGE: unsetenv NAME\n");
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
/**
 * _uitoa - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa(unsigned int count)
{
char *numstr;
unsigned int tmp, digits;

tmp = count;
for (digits = 0; tmp != 0; digits++)
tmp /= 10;
numstr = malloc(sizeof(char) * (digits + 1));
if (numstr == NULL)
{
perror("Fatal Error1");
exit(127);
}
numstr[digits] = '\0';
for (--digits; count; --digits)
{
numstr[digits] = (count % 10) + '0';
count /= 10;
}
return (numstr);
}


/**
* help - help builtins
* @args: array of arguments
* Return: 1 or error
*/
int help(char **args)
{
int i;
if (args[1])
{
for (i = 0; i < num_builtins(); i++)
{
if (_strcmp(builtin_str[i], args[1]) == 0)
{
_puts(builtins_help[i]);
}
}

return (1);
}

_puts("Holshell,  \n");
_puts("These shell commands are defined internally.");
_puts("  Type `help' to see this list.");
_puts("Type `help name' to find out more about the function `name'..\n");
_puts("The following are built in:\n");

for (i = 0; i < num_builtins(); i++)
{
_puts("  ");
_puts(builtin_str[i]);
_puts("\n");
}

_puts("Use the man command for information on other programs.\n");
return (1);
}
/**
* exitshell - exit builtins
* @args: array of arguments
* Return: 1 or error
*/
int exitshell(char **args)
{
if (args[1])
exit(atoi(args[1]));
exit(EXIT_SUCCESS);
}

/* Shell function implementations. */

/**
* execute - execute th ecommand
* @args: array of arguments
* Return: 1 or error
*/
int execute(char **args)
{
int i = 0;
char **array;
struct stat st;
char *PATH;
char *str;
char *cmd;

PATH = _getenv("PATH");
if (args[0] == NULL)
/* An empty command was entered. */
return (1);

for (i = 0; i < num_builtins(); i++)
{
if (_strcmp(args[0], builtin_str[i]) == 0)

return ((*builtin_func[i])(args));
}
array = split_line(strdup(PATH), ":");
for (i = 0; array[i]; i++)
{
str = str_concat(array[i], "/");
cmd = str_concat(str, args[0]);
if (stat(cmd, &st) == 0)
{
args[0] = cmd;
break;
}
}

return (launch_cmd(args));
}

/**
* launch_cmd - fork and laun the cmd
* @args: array of arguments
* Return: 1 or error
*/
int launch_cmd(char **args)
{
pid_t pid, wpid;
int status;
char *name = _getenv("_");

pid = fork();
if (pid == 0)
{

/* Child process */
if (execve(args[0], args, environ) == -1)
{
__puts(name);
__puts(": ");
__puts(args[0]);
__puts(": not found\n");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error forking */
perror(name);
}
else
{
/* Parent process */
do {
wpid = waitpid(pid, &status, WUNTRACED);
if (!wpid)
{
perror(name);
}

} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}

/**
* split_line - slplit string to array
* @line: string to stplit
* @delim: split delimator
* Return: array of strings
*/
char **split_line(char *line, char *delim)
{
int bufsize = TOK_BUFSIZE, i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
char *name = _getenv("_");

if (!tokens)
{
perror(name);
exit(EXIT_FAILURE);
}

token = strtok(line, delim);
while (token != NULL)
{
tokens[i] = token;
i++;

if (i >= bufsize)
{
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror(name);
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, delim);
}
tokens[i] = NULL;
return (tokens);
}
/**
* sigintHandler - signal handler
* @sig_num: sig num
* Return: void
*/
void sigintHandler(int sig_num __attribute__((unused)))
{
signal(SIGINT, sigintHandler);
_puts("\n");
display_prompt();
fflush(stdout);
}

/**
* read_line - read line from stdin
* Return: string
*/
char *read_line(void)
{
int bufsize = BUFSIZE;
int i = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;
char *name = getenv("");

if (!buffer)
{
perror(name);
exit(EXIT_FAILURE);
}

while (1)
{
signal(SIGINT, sigintHandler);
c = getchar();
if (c == EOF)
{
exit(0);
}

if (c == EOF || c == '\n')
{
buffer[i] = '\0';
return (buffer);
}
else
{
buffer[i] = c;
}
i++;

if (i >= bufsize)
{
bufsize += BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
perror(name);
exit(EXIT_FAILURE);
}
}
}
}

/**
* display_prompt - print prompt
* Return: void
*/
void display_prompt(void)
{
char *PWD = _getenv("PWD");
char *HOME = _getenv("HOME");
char subPWD[BUFSIZE] = "~";
unsigned int i;

if (strncmp(HOME, PWD, _strlen(HOME)) == 0)
{
for (i = _strlen(HOME); i < _strlen(PWD); i++)
subPWD[i - _strlen(HOME) + 1] = PWD[i];

_puts(_getenv("USERNAME"));
_puts("@shell");
_puts(subPWD);
_puts("$> ");
}
else
{
_puts(_getenv("USERNAME"));
_puts("@shell");
_puts(PWD);
_puts("$> ");
}
}

/**
* shell_loop - repeat shell loop
* Return: void
*/
void shell_loop(void)
{
char *line;
char **args;
int status;
int i;

do {
display_prompt();
line = read_line();

args = split_line(line, TOK_DELIM);

for (i = 0; i < alicount; i++)
{
if (_strcmp(args[0], aliass[i].name) == 0)
{
args[0] = strdup(aliass[i].value);
}
}

status = execute(args);

free(line);
free(args);

} while (status);
}
