#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <libgen.h> // Include this header for basename()
#include "../include/shell.h"
#include "../include/custom_ui_modules.h"
#include "../include/utilities.h"
#include "../include/alpha_router.h"

char selected_model[50] = "gemini"; // Default model

void execute_command(char *input)
{
    char *args[MAX_INPUT_SIZE / 2 + 1];
    char *token = strtok(input, " ");
    int i = 0;

    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (args[0] == NULL)
    {
        return;
    }

    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1])
        {
            if (chdir(args[1]) != 0)
                perror("cd failed");
        }
        else
        {
            fprintf(stderr, "cd: expected argument\n");
        }
        return;
    }

    if (strcmp(args[0], "alpha") == 0)
    {
        route_alpha_command(args);
        return;
    }

    pid_t pid = fork();
    if (pid == 0)
    {
        execvp(args[0], args);
        perror("Command not found");
        exit(1);
    }
    else
    {
        wait(NULL);
    }
}