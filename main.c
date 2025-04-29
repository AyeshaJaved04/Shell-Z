#include <stdio.h>
#include "./include/intro_modules.h"
#include "./include/shell.h"
#include "./include/utilities.h"
#include "./include/custom_ui_modules.h"

#define MAX_INPUT_SIZE 1024
#define HISTORY_SIZE 10

void execute_brew_install(const char *package_name)
{
    char command[MAX_INPUT_SIZE];
    snprintf(command, sizeof(command), "brew install %s", package_name);
    int result = system(command);

    if (result == 0)
    {
        printf("✅ Package '%s' installed successfully.\n", package_name);
    }
    else
    {
        printf("❌ Failed to install package '%s'.\n", package_name);
    }
}

int main()
{
start:

    // system("clear");
    intro();

    char input[MAX_INPUT_SIZE];
    char command_history[HISTORY_SIZE][MAX_INPUT_SIZE];
    int history_index = 0;
    int total_commands = 0;

    gotoxy(0, 24);
    animate("You're all set to dive into a smarter and a faster terminal experience!\n", 50, 0, 32);
    animate("Type \033[1;36m \'ls\' \033[0;32m to get started...\n\n", 35, 0, 32);
    char ls_command[1024];

    BOLD_GREEN_TEXT("apple~$ ");
    RESET();
    fgets(ls_command, 1024, stdin);
    system(ls_command);

    ls_command[strcspn(ls_command, "\n")] = 0;

    if (strcmp(ls_command, "ls") == 0)
    {
        animate("\n\033[1;33mCongratulations!\033[0;32m You've just unlocked your first Shell-Z command!\n", 50, 0, 33);
        animate("Pro Tip: Use \033[1;36m'alpha help'\033[0;32m to see what Shell-Z can do for you next!\n\n", 45, 0, 32);
    }
    else
    {
        animate("\n🤔Hmmm... That wasn't \033[1m'ls'.\033[0;32m Try typing \033[1;33m'ls'\033[0;32m to begin.\n\n", 40, 0, 31);
    }

    fflush(stdin);

    while (1)
    {
        // signal(SIGINT, custom_sigint_handler);

        BOLD_GREEN_TEXT("apple~$ ");
        RESET();
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
        {
            break;
        }

        printf("\n");

        input[strcspn(input, "\n")] = 0; // Remove newline

        strncpy(command_history[history_index % HISTORY_SIZE], input, MAX_INPUT_SIZE);
        history_index++;
        total_commands++;

        if (strcmp(input, "alpha restart") == 0)
        {
            goto start;
        }

        if (strcmp(input, "alpha show history") == 0)
        {
            show_history(command_history, history_index, total_commands);
            continue;
        }

        execute_command(input);
        printf("\n");
    }

    return 0;
}