#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./include/intro_modules.h"
#include "./include/shell.h"
#include "./include/utilities.h"
#include "./include/custom_ui_modules.h"
#include "./include/menu.h"

#define MAX_INPUT_SIZE 1024
#define HISTORY_SIZE 10

// Global variable to control animations
int g_enable_animations = 1;

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
    int choice = show_start_menu();
    if (choice == 0)
    {
        g_enable_animations = 0;
    }
    else
    {
        g_enable_animations = 1;
    }

start:
    if (g_enable_animations)
    {
        intro();
    }
    else
    {
        // For simple mode, just clear the screen, show the static logo,
        // and add spacing before the prompt.
        system("clear");
        display_logo();
        printf("\n\n\n");
    }

    char input[MAX_INPUT_SIZE];
    char command_history[HISTORY_SIZE][MAX_INPUT_SIZE];
    int history_index = 0;
    int total_commands = 0;

    while (1)
    {
        BOLD_GREEN_TEXT("apple~$ ");
        RESET();
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
        {
            printf("\n");
            break;
        }

        printf("\n");
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) > 0)
        {
            strncpy(command_history[history_index % HISTORY_SIZE], input, MAX_INPUT_SIZE);
            history_index++;
            total_commands++;
        }

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