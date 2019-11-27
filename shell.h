#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
/******Variable And Struct Declarations******/
#define BUFSIZE 1024
#define INPBUF 128
#define ARGMAX 16
#define FNAME_LEN 20
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"
#define ALS_DELIM "=''\t\r\n\a"

extern char **environ;
/**
 * struct alias - Defines a alias attributes
 * @name: the name
 * @value: the value
 */
typedef struct alias
{
char *name;
char *value;
} alias_t;

alias_t *aliass;
int alicount;
char **history_list;
int hiscount;


/******Function Declarations******/

char *_strdup(char *strtodup);
int _strcmp(char *s1, char *s2);
char *_strcat(char *strc1, char *strc2);
unsigned int _strlen(char *str);
char *_strtok(char *str, const char *delim);
int _puts(const char *s);
char *str_concat(char *s1, char *s2);
int _putchar(char c);

char **_realloc(char **ptr, size_t *size);

char *_getenv(char *name);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
/*Function Declarations for builtin shell commands:*/
int cd(char **args);
int help(char **args);
int exitshell(char **args);
int history(char **args);
int env(char **args);
int b_setenv(char **args);
int b_unsetenv(char **args);
int alias(char **args);

/* char *getcwd(char *buf, size_t size);*/
void  display_prompt(void);
void shell_loop(void);
char *read_line(void);
char **split_line(char *line, char *delim);
int launch_cmd(char **args);
int execute(char **args);
void sigintHandler(int sig_num);
#endif /* _SHELL_H_ */
