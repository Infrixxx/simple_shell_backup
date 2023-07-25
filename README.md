### `0x16.c-Simple shell`
Project to built shell from scratch

### `Learning Objective`
To be able to incorporate current knowledge of C to build complex projects


## Files : ##

1. `check_executable.c`: This file contains the implementation of the `check_executable` function, which checks if a given command is an executable file.

2. `execute_command.c`: This file contains the implementation of the `execute_command` function, which takes a command entered by the user and executes it.

3. `execute_command_with_args.c`: This file contains the implementation of the `execute_command_with_args` function, which is responsible for executing the command with its arguments in a child process.

4. `main.c`: This file contains the `main` function, which serves as the entry point of the Simple Shell program. It runs the main loop of the shell, reading user commands and executing them.

5. `prompt.c`: This file contains the implementation of the `display_prompt` function, which displays the shell prompt to the user.

6. `read_command.c`: This file contains the implementation of the `read_command` function, which reads a command from the user.

7. `shell.c`: This file contains the `main` function, which runs the main loop of the shell, reading user commands and executing them.

8. `shell.h`: This header file contains function prototypes, macro definitions, and any global variable declarations that are shared across different source files. It ensures proper communication and visibility of functions and variables among different parts of the shell program.

9. `tokenize_command.c`: This file contains the implementation of the `tokenize_command` function, which tokenizes a command into individual arguments.

10. `env_builtin.c`: Contains the implementation of the `env_builtin()` function, which prints the current environment variables.

11. `custom_getline.c`: This file contains the implementation of the `custom_getline(void)` function, which reads input from the standard input using a buffer to minimize the number of read system calls.

12. `custom_strtok.c` : This file contains the implementation of the `char *custom_strtok(char *str, const char *delimiters)` function,the custom_strtok function is a custom implementation of the strtok function in C.

13. `custom_atoi.c` : Custom implementation of the atoi function.

14. `free_arguments.c` : Free the memory allocated for an array of strings.

15. `builtins.c` is a source file containing the implementations of the built-in commands for our custom shell application. Built-in commands are fundamental functionalities recognized and executed directly by the shell, rather than external programs.

Functions in `builtins.c`:

1. `int setenv_builtin(char **args)`: Implements the `setenv` built-in command to initialize or modify environment variables. It expects `args[1]` as the variable name and `args[2]` as the value. Prints usage instructions on incorrect syntax and returns `-1` on failure.

2. `int unsetenv_builtin(char **args)`: Implements the `unsetenv` built-in command to remove environment variables. It expects `args[1]` as the variable name. Prints usage instructions on incorrect syntax and returns `-1` on failure.

These functions handle the execution of built-in commands in the shell, making interactions with the shell environment more convenient.

16. `builtins1.c` is a C source file that implements the built-in command `cd` for our simple shell program. The file defines the `cd_builtin` function, which allows the user to change the current working directory of the shell process.

**Functions:**

1. `int cd_builtin(char **args)`: This function is the implementation of the `cd` built-in command. It takes an array of command arguments as input, where `args[0]` is expected to be the command "cd" and `args[1]` (if present) is the directory path to change to. The function first checks for special cases where no directory is provided or when the user wants to change to the previous working directory using `cd -`. It then updates the current working directory using `chdir()` and updates the `PWD` environment variable to reflect the new directory.

2. `static char *get_home_directory(void)`: This is a helper function that retrieves the user's home directory path from the `HOME` environment variable. If the variable is not set, it prints an error message to `stderr` and returns NULL.

3. `static char *get_oldpwd_directory(void)`: This is another helper function that retrieves the previous working directory path from the `OLDPWD` environment variable. If the variable is not set, it prints an error message to `stderr` and returns NULL.

When you compile and link all these files together, you will have a complete Simple Shell program capable of accepting user commands, executing them (with or without arguments), displaying the prompt, and handling any errors that may occur during execution. The split-up implementation allows for better code organization and maintainability, making it easier to understand and modify specific parts of the shell functionality as needed.
