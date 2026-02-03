#include "shell.h"

/**
 * execute_command - executes a command line
 * @line: command string
 * @shell_name: name of the shell program (argv[0])
 *
 * Return: 0 on success, -1 to exit
 */
int execute_command(char *line, char *shell_name)
{
    char *args[100];  /* simple argument array */
    char *token;
    pid_t pid;
    int i = 0, status;

    /* Tokenize input string by spaces */
    token = strtok(line, " ");
    while (token != NULL && i < 99)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    /* Built-in command: exit */
    if (strcmp(args[0], "exit") == 0)
        return (-1);

    /* Fork child process */
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (0);
    }

    if (pid == 0)  /* Child process */
    {
        if (execve(args[0], args, NULL) == -1)
        {
            fprintf(stderr, "%s: 1: %s: not found\n", shell_name, args[0]);
            _exit(127);
        }
    }
    else  /* Parent process */
        waitpid(pid, &status, 0);

    return (0);
}
