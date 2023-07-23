#ifndef _SHELL_H_
#define _SHELL_H_

/*Libraries*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*MACROS */

#define BUFFER_SIZE 1024
#define LINE_BUFFER_SIZE 128

/*Function prototypes*/
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
char **tokenize_command(char *command);
void execute_command_with_args(char **args);
int check_executable(char *command);
void env_builtin(void);
char *custom_getline(void);

#endif /* SHELL_H */
