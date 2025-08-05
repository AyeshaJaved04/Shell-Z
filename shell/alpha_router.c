#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <libgen.h>
#include "../include/alpha_router.h"
#include "../include/shell.h"
#include "../include/custom_ui_modules.h"
#include "../include/utilities.h"

void route_alpha_command(char **args)
{
    if (args[1] == NULL)
    {
        printf("Unknown 'alpha' command.\n");
        return;
    }

    if (strcmp(args[1], "git") == 0 && args[2])
    {
        if (strcmp(args[2], "init") == 0)
        {
            system("/app/scripts/git_init.sh");
            return;
        }
    }

    if (strcmp(args[1], "clone") == 0 && args[2])
    {
        if (strcmp(args[2], "all") == 0 || strcmp(args[2], "-a") == 0)
        {
            system("/app/scripts/git_clone_all.sh");
            return;
        }
    }

    if (strcmp(args[1], "fetch") == 0 && args[2])
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

    if (strcmp(args[1], "react") == 0 && args[2])
    {
        if (strcmp(args[2], "init") == 0)
        {
            system("/app/scripts/react_init.sh");
            return;
        }
    }

    if (strcmp(args[1], "next") == 0 && args[2])
    {
        if (strcmp(args[2], "init") == 0)
        {
            system("/app/scripts/next_init.sh");
            return;
        }
    }

    if (strcmp(args[1], "install") == 0 && args[2])
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

    if (strcmp(args[1], "add") == 0 && args[2])
    {
        struct stat st;
        if (stat(args[2], &st) == 0 && S_ISDIR(st.st_mode))
        {
            char command[1024];
            snprintf(command, sizeof(command), "cp -r %s /app/server/static/pages/", args[2]);

            int status = system(command);

            if (status == 0)
            {
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

                free(path_copy);
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

    if (strcmp(args[1], "make") == 0 || strcmp(args[1], "build") == 0)
    {
        system("make");
        return;
    }

    if (strcmp(args[1], "clean") == 0 && !args[2])
    {
        system("make clean");
        return;
    }

    if (strcmp(args[1], "current") == 0 && args[2])
    {
        if (strcmp(args[2], "model") == 0)
        {
            GREEN();
            printf("Model in use: %s\n", selected_model);
        }
        return;
    }

    if (strcmp(args[1], "use") == 0 && args[2])
    {
        strncpy(selected_model, args[2], sizeof(selected_model) - 1);
        selected_model[sizeof(selected_model) - 1] = '\0';
        GREEN();
        printf("Model changed to: %s\n", selected_model);
        return;
    }

    if (strcmp(args[1], "clean") == 0 && args[2])
    {
        if (strcmp(args[2], "server") == 0)
        {
            system("cd /app/server/ && make clean");
            return;
        }
        else if (strcmp(args[2], "scheduler") == 0)
        {
            system("cd /app/scheduler/ && make clean");
            return;
        }
    }

    if ((strcmp(args[1], "run") == 0) || (strcmp(args[1], "start") == 0))
    {
        if (args[2] && ((strcmp(args[2], "server") == 0) || (strcmp(args[2], "dev") == 0)))
        {
            system("cd /app/server/ && make");
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

    if ((strcmp(args[1], "explain") == 0 || strcmp(args[1], "generate") == 0 || strcmp(args[1], "ask") == 0) && args[2])
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

    if (strcmp(args[1], "exit") == 0)
    {
        alpha_exit();
        exit(0);
    }

    if (strcmp(args[1], "show") == 0 && args[2])
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

    if (strcmp(args[1], "list") == 0 && args[2])
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

    if (strcmp(args[1], "help") == 0)
    {
        help();
        return;
    }

    if (strcmp(args[1], "guide") == 0)
    {
        show_guide();
        return;
    }

    if (strcmp(args[1], "who") == 0)
    {
        who();
        return;
    }

    if (strcmp(args[1], "clear") == 0)
    {
        system("clear");
        return;
    }

    RED();
    printf("Unknown 'alpha' command.\n");
}
