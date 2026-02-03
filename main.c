#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: Argument count (unused)
 * @argv: Argument vector (used for program name)
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    (void)argc;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (line[0] == '\0')
            continue;

        if (execute_command(line, argv[0]) == -1)
            break;
    }

    free(line);
    return (0);
}
