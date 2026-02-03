#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include "shell.h"

extern char **environ;

int main(int argc, char **argv)
{
    char *line;
    size_t len;
    ssize_t nread;
    int interactive;

    (void)argc;

    line = NULL;
    len = 0;
    interactive = isatty(STDIN_FILENO);

    while (1)
    {
        if (interactive)
        {
            printf("($) ");
            fflush(stdout);
        }

        nread = getline(&line, &len, stdin);
        if (nread == -1) /* Ctrl+D or EOF */
        {
            free(line);
            if (interactive)
                printf("\n");
            exit(0);
        }

        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        execute_command(line, argv[0]);
    }

    free(line);
    return 0;
}
