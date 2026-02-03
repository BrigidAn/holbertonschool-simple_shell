#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

extern char **environ;

void execute_command(char *command, char *prog_name)
{
    pid_t pid;
    int status;
    char *args[2];

    /* Trim leading spaces */
    while (*command == ' ' || *command == '\t')
        command++;

    /* Ignore empty lines */
    if (*command == '\0')
        return;

    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        return;
    }

    if (pid == 0) /* Child process */
    {
        args[0] = command;
        args[1] = NULL;

        if (execve(command, args, environ) == -1)
        {
            fprintf(stderr, "%s: 1: %s: not found\n", prog_name, command);
            _exit(127);
        }
    }
    else /* Parent process */
    {
        waitpid(pid, &status, 0);
    }
}
