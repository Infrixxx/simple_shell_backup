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
char *custom_strtok(char *str, const char *delimiters);
int custom_atoi(const char *str);
void free_arguments(char **args);
int setenv_builtin(char **args);
int unsetenv_builtin(char **args);
int execute_builtin(char **args);
int cd_builtin(char **args);
#endif /* SHELL_H */
