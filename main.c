#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    (void)argc;  /* Not used in this simple example */

    while (1)
    {
        /* Display prompt if interactive */
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);

        nread = getline(&line, &len, stdin);
        if (nread == -1)  /* EOF or error */
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        /* Remove newline character */
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (line[0] == '\0')  /* Empty input */
            continue;

        if (execute_command(line, argv[0]) == -1)  /* shell.c function */
            break;
    }

    free(line);
    return (0);
}
