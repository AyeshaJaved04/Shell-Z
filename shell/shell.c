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
                system("/app/scripts/git_init.sh");
                return;
            }
        }

        if (args[1] && strcmp(args[1], "clone") == 0 && args[2])
        {
            if (strcmp(args[2], "all") == 0 || strcmp(args[2], "-a") == 0)
            {
                system("/app/scripts/git_clone_all.sh");
                return;
            }
        }

        if (args[1] && strcmp(args[1], "fetch") == 0 && args[2])
        {
            if (strcmp(args[2], "github") == 0 && args[3])
            {
                if (strcmp(args[3], "profile") == 0)
                {
                    system("/app/scripts/get_github_info.sh");
                    return;
                }
            }
        }

        if (args[1] && strcmp(args[1], "react") == 0 && args[2])
        {
            if (strcmp(args[2], "init") == 0)
            {
                system("/app/scripts/react_init.sh");
                return;
            }
        }

        if (args[1] && strcmp(args[1], "next") == 0 && args[2])
        {
            if (strcmp(args[2], "init") == 0)
            {
                system("/app/scripts/next_init.sh");
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
            // validate that the source path is a valid directory.
            struct stat st;
            if (stat(args[2], &st) == 0 && S_ISDIR(st.st_mode))
            {
                // This copies the entire source folder into the 'pages' directory.
                char command[1024];
                snprintf(command, sizeof(command), "cp -r %s /app/server/static/pages/", args[2]);

                int status = system(command);

                if (status == 0)
                {
                    // To create the URL, get the base name of the folder that was copied.
                    char *path_copy = strdup(args[2]);
                    if (path_copy == NULL)
                    {
                        perror("strdup");
                        return;
                    }
                    char *dir_name = basename(path_copy);

                    printf("\t ✅ PAGE ADDED SUCCESSFULLY!!!\n\n");
                    GREEN();
                    printf("   View it at: \033[0;34mhttp://localhost:8080/pages/%s/\033[0m\n", dir_name);
                    RESET();
                    YELLOW();
                    printf("      Run the server using 'alpha run server'\n");
                    RESET();

                    free(path_copy); // Clean up the duplicated string
                }
                else
                {
                    fprintf(stderr, "❌ Failed to copy the folder.\n");
                }
            }
            else
            {
                printf("❌ Provided path is invalid or not a directory.\n");
            }
            return;
        }

        if (args[1] && (strcmp(args[1], "make") == 0 || strcmp(args[1], "build") == 0))
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
                system("cd /app/server/ && make clean");
                return;
            }
            else if (args[2] && (strcmp(args[2], "scheduler") == 0))
            {
                system("cd /app/scheduler/ && make clean");
                return;
            }
        }

        if (args[1] && ((strcmp(args[1], "run") == 0) || (strcmp(args[1], "start") == 0)))
        {
            if (args[2] && ((strcmp(args[2], "server") == 0) || (strcmp(args[2], "dev") == 0)))
            {
                system("cd /app/server/ && make");
                // system("pwd");
                system("cd /app/server/ && ./bin/server");
                return;
            }

            else if (args[2] && (strcmp(args[2], "scheduler") == 0))
            {

                system("cd /app/scheduler/ && make");
                system("cd /app/scheduler/ && ./bin/cpu_scheduling");
                return;
            }
        }

        if (args[1] && (strcmp(args[1], "explain") == 0 || strcmp(args[1], "generate") == 0 || strcmp(args[1], "ask") == 0) && args[2])
        {
            char python_cmd[MAX_INPUT_SIZE] = "python3 /app/shell/main.py \"";
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