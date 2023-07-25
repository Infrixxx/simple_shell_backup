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

/*Structure to hold an alias*/
typedef struct Alias
{
	char *name;
	char *value;
	struct Alias *next;
} Alias;

/*LIST*/
extern Alias *alias_list;

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
void execute_commands_separated_by_semicolon(char *command);
void execute_commands_separated_by_logical_and(char *command);
void execute_commands_separated_by_logical_or(char *command);
void execute_single_command(char **args);
void add_alias(Alias **alias_list, char *name, char *value);
char *get_alias_value(Alias *alias_list, char *name);
void print_aliases(Alias *alias_list, char **names);
int alias_builtin(char **args);
char *replace_variables(char *command);
int custom_strlen(char **arr);
void execute_child_process(char **args);

#endif /* SHELL_H */

