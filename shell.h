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
#endif /* _SHELL_H_ */
