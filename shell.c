#include "shell.h"

/**
 * execute_command - executes a command line
 * @line: Command string
 * @shell_name: Name of the shell program
 *
 * Return: 0 to continue, -1 to exit shell
 */
int execute_command(char *line, char *shell_name)
{
    char *args[100];
    char *token;
    pid_t pid;
    int i = 0, status;

    token = strtok(line, " ");
    while (token != NULL && i < 99)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0)
        return (-1);

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (0);
    }

    if (pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            fprintf(stderr, "%s: 1: %s: not found\n", shell_name, args[0]);
            _exit(127);
        }
    }
    else
        waitpid(pid, &status, 0);

    return (0);
}
