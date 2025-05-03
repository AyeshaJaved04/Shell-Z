#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "../include/shell.h"
#include "../include/custom_ui_modules.h"
#include "../include/utilities.h"

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
        if (args[1] && strcmp(args[1], "git") == 0 && args[2])
        {
            if (strcmp(args[2], "init") == 0)
            {
                system("/Users/alpha/Developer/os_final/Shell-Z/scripts/git_init.sh");
                return;
            }
        }

        if (args[1] && strcmp(args[1], "clone") == 0 && args[2])
        {
            if (strcmp(args[2], "all") == 0 || strcmp(args[2], "-a") == 0)
            {
                system("/Users/alpha/Developer/Shell-Z_v.1.0/scripts/git_clone_all.sh");
                return;
            }
        }

        if (args[1] && strcmp(args[1], "fetch") == 0 && args[2])
        {
            if (strcmp(args[2], "github") == 0 && args[3])
            {
                if (strcmp(args[3], "profile") == 0)
                {
                    system("/Users/alpha/Developer/Shell-Z_v.1.0/scripts/get_github_info.sh");
                    return;
                }
            }
        }

        if (args[1] && strcmp(args[1], "react") == 0 && args[2])
        {
            if (strcmp(args[2], "init") == 0)
            {
                system("/Users/alpha/Developer/Shell-Z_v.1.0/scripts/react_init.sh");
                return;
            }
        }

        if (args[1] && strcmp(args[1], "next") == 0 && args[2])
        {
            if (strcmp(args[2], "init") == 0)
            {
                system("/Users/alpha/Developer/Shell-Z_v.1.0/scripts/next_init.sh");
                return;
            }
        }
        if (args[1] && strcmp(args[1], "install") == 0 && args[2])
        {
            char command[1024];
            snprintf(command, sizeof(command), "brew install %s", args[2]);

            int result = system(command);
            if (result == 0)
            {
                printf("\n\n\t✅ '%s' installed successfully.\n", args[2]);
            }
            else
            {
                printf("\n\n\t❌ Failed to install '%s'.\n", args[2]);
            }
            return;
        }

        if (args[1] && strcmp(args[1], "add") == 0 && args[2])
        {
            struct stat st;
            if (stat(args[2], &st) == 0 && S_ISDIR(st.st_mode))
            {
                char command[512];
                snprintf(command, sizeof(command), "cp -r %s /Users/alpha/Developer/Shell-Z_v.1.0/server/static/pages/", args[2]);
                int status = system(command);
                if (status == 0)
                    printf("Page added successfully.\n");
                else
                    printf("Failed to add page.\n");
            }
            else
            {
                printf("Provided path is invalid or not a directory.\n");
            }
            return;
        }

        if (args[1] && strcmp(args[1], "make") == 0)
        {
            system("make");
            return;
        }

        if (args[1] && strcmp(args[1], "clean") == 0 && !args[2])
        {
            system("make clean");
            return;
        }

        if (args[1] && strcmp(args[1], "current") == 0 && args[2])
        {
            if (strcmp(args[2], "model") == 0)
            {
                GREEN();
                printf("Model in use: %s\n", selected_model);
            }

            return;
        }

        if (args[1] && strcmp(args[1], "use") == 0 && args[2])
        {
            strncpy(selected_model, args[2], sizeof(selected_model) - 1);
            selected_model[sizeof(selected_model) - 1] = '\0'; // Always null-terminate
            GREEN();
            printf("Model changed to: %s\n", selected_model);
            return;
        }

        if (args[1] && ((strcmp(args[1], "clean") == 0)) && args[2])
        {
            if (args[2] && (strcmp(args[2], "server") == 0))
            {
                system("cd /Users/alpha/Developer/Shell-Z_v.1.0/server/ && make clean");
                return;
            }
            else if (args[2] && (strcmp(args[2], "scheduler") == 0))
            {
                system("cd /Users/alpha/Developer/Shell-Z_v.1.0/scheduler/ && make clean");
                return;
            }
        }

        if (args[1] && ((strcmp(args[1], "run") == 0) || (strcmp(args[1], "start") == 0)))
        {
            if (args[2] && ((strcmp(args[2], "server") == 0) || (strcmp(args[2], "dev") == 0)))
            {
                system("cd /Users/alpha/Developer/Shell-Z_v.1.0/server/ && make");
                // system("pwd");
                system("cd /Users/alpha/Developer/Shell-Z_v.1.0/server/ && ./bin/server");
                return;
            }

            else if (args[2] && (strcmp(args[2], "scheduler") == 0))
            {

                system("cd /Users/alpha/Developer/Shell-Z_v.1.0/scheduler/ && make");
                system("cd /Users/alpha/Developer/Shell-Z_v.1.0/scheduler/ && ./bin/cpu_scheduling");
                return;
            }
        }

        if (args[1] && (strcmp(args[1], "explain") == 0 || strcmp(args[1], "generate") == 0 || strcmp(args[1], "ask") == 0) && args[2])
        {
            char python_cmd[MAX_INPUT_SIZE] = "python3 /Users/alpha/Developer/Shell-Z_v.1.0/shell/main.py \"";
            for (int j = 2; args[j]; j++)
            {
                strcat(python_cmd, args[j]);
                if (args[j + 1])
                    strcat(python_cmd, " ");
            }
            strcat(python_cmd, "\" ");
            strcat(python_cmd, selected_model);
            system(python_cmd);
            return;
        }

        if (args[1] && strcmp(args[1], "exit") == 0)
        {
            alpha_exit();
            exit(0);
        }

        if (args[1] && strcmp(args[1], "show") == 0 && args[2])
        {
            if (strcmp(args[2], "server") == 0 && args[3] && strcmp(args[3], "details") == 0)
            {
                show_server_details();
                return;
            }
            if (strcmp(args[2], "scheduler") == 0 && args[3] && strcmp(args[3], "details") == 0)
            {
                show_scheduler_details();
                return;
            }
        }

        if (args[1] && strcmp(args[1], "list") == 0 && args[2])
        {
            if ((strcmp(args[2], "all") == 0 && args[3] && strcmp(args[3], "commands") == 0) || (strcmp(args[2], "--all") == 0) || ((strcmp(args[2], "-a") == 0)))
            {
                list_all_commands();
                return;
            }
            else if (strcmp(args[2], "scripts") == 0)
            {
                list_scripts();
                return;
            }
            else if (strcmp(args[2], "models") == 0)
            {
                list_models();
                return;
            }
            else if ((strcmp(args[2], "comrades") == 0) || (strcmp(args[2], "team") == 0) || strcmp(args[2], "developers") == 0 || strcmp(args[2], "devs") == 0)
            {
                list_comrades();
                return;
            }
            else if ((strcmp(args[2], "contributors") == 0 || strcmp(args[2], "roles") == 0 || strcmp(args[2], "contributions") == 0))
            {
                list_contributors();
                return;
            }
        }

        if (args[1] && strcmp(args[1], "help") == 0)
        {
            help();
            return;
        }

        if (args[1] && strcmp(args[1], "guide") == 0)
        {
            show_guide();
            return;
        }

        if (args[1] && strcmp(args[1], "who") == 0)
        {
            who();
            return;
        }

        if (args[1] && (strcmp(args[1], "clear") == 0))
        {
            system("clear");
            return;
        }

        RED();
        printf("Unknown 'alpha' command.\n");
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
