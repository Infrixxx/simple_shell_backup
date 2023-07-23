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

When you compile and link all these files together, you will have a complete Simple Shell program capable of accepting user commands, executing them (with or without arguments), displaying the prompt, and handling any errors that may occur during execution. The split-up implementation allows for better code organization and maintainability, making it easier to understand and modify specific parts of the shell functionality as needed.
