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

