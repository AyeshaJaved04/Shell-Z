#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../include/intro_modules.h"
#include "../include/utilities.h"

void printArts()
{
    usleep(350000);
    GREEN();

    gotoxy(45, 3);
    printf("  ____  _          _ _      _____  \n");
    gotoxy(45, 4);
    printf(" / ___|| |__   ___| | |    |__  /  \n");
    gotoxy(45, 5);
    printf(" \\___ \\| '_ \\ / _ \\ | |_____ / /   \n");
    gotoxy(45, 6);
    printf("  ___) | | | |  __/ | |_____/ /_   \n");
    gotoxy(45, 7);
    printf(" |____/|_| |_|\\___|_|_|    /____|  \n");

    sleep(1);

    gotoxy(37, 10);
    printf("  ___  \n");
    gotoxy(37, 11);
    printf(" / _ \\ \n");
    gotoxy(37, 12);
    printf("/ /_\\ \\ \n");
    gotoxy(37, 13);
    printf("|  _  | \n");
    gotoxy(37, 14);
    printf("| | | | \n");
    gotoxy(37, 15);
    printf("\\_| |_/\n");

    usleep(250000);

    gotoxy(47, 10);
    printf("______          _           _   \n");
    gotoxy(47, 11);
    printf("| ___ \\        (_)         | |  \n");
    gotoxy(47, 12);
    printf("| |_/ / __ ___  _  ___  ___| |_ \n");
    gotoxy(47, 13);
    printf("|  __/ '__/ _ \\| |/ _ \\/ __| __|\n");
    gotoxy(47, 14);
    printf("| |  | | | (_) | |  __/ (__| |_ \n");
    gotoxy(47, 15);
    printf("\\_|  |_|  \\___/| |\\___|\\___|\\__|\n");
    gotoxy(47, 16);
    printf("              _/ |              \n");
    gotoxy(47, 17);
    printf("             |__/                \n");

    usleep(250000);

    gotoxy(82, 10);
    printf("______       \n");
    gotoxy(82, 11);
    printf("| ___ \\      \n");
    gotoxy(82, 12);
    printf("| |_/ /_   _ \n");
    gotoxy(82, 13);
    printf("| ___ \\ | | |\n");
    gotoxy(82, 14);
    printf("| |_/ / |_| |\n");
    gotoxy(82, 15);
    printf("\\____/ \\__, |\n");
    gotoxy(82, 16);
    printf("        __/ |\n");
    gotoxy(82, 17);
    printf("       |___/ \n");

    YELLOW();
    sleep(1);

    gotoxy(29, 19);
    printf(" _____                        _____ ________  _________  ___ ______ _____ _____ \n");
    gotoxy(29, 20);
    printf("|_   _|                      /  __ \\  _  |  \\/  || ___ \\/ _ \\|  _  \\  ___/  ___|\n");
    gotoxy(29, 21);
    printf("  | | ___  __ _ _ __ ___     | /  \\/ | | | .  . || |_/ / /_\\ \\ | | | |__ \\ `--. \n");
    gotoxy(29, 22);
    printf("  | |/ _ \\/ _` | '_ ` _ \\    | |   | | | | |\\/| ||    /|  _  | | | |  __| `--. \\\n");
    gotoxy(29, 23);
    printf("  | |  __/ (_| | | | | | |   | \\__/\\ \\_/ / |  | || |\\ \\| | | | |/ /| |___/\\__/ /\n");
    gotoxy(29, 24);
    printf("  \\_/\\___|\\__,_|_| |_| |_|    \\____/\\___/\\_|  |_/\\_| \\_\\_| |_/___/ \\____/\\____/ \n");

    GREEN();
    sleep(2);
    system("clear");
    gotoxy(45, 3);
    printf("  ____  _          _ _      _____  \n");
    gotoxy(45, 4);
    printf(" / ___|| |__   ___| | |    |__  /  \n");
    gotoxy(45, 5);
    printf(" \\___ \\| '_ \\ / _ \\ | |_____ / /   \n");
    gotoxy(45, 6);
    printf("  ___) | | | |  __/ | |_____/ /_   \n");
    gotoxy(45, 7);
    printf(" |____/|_| |_|\\___|_|_|    /____|  \n");
    RESET();

}

void printDetails()
{
    gotoxy(13, 16);

    sleep(1);
    animate("This is Shell-Z!", 150, 1, 33);
    usleep(400000);
    animate(" An intelligent and feature-rich Command-Line Environment designed to boost Your Productivity.\n", 25, 1, 32);

    gotoxy(60, 20);
    BLACK();
    BG_WHITE();
    sleep(1);
    printf(" \033[1mHOLD ON! ");
    RESET();

    gotoxy(48, 22);
    animate("Initializing Shell-Z environment...", 50, 1, 32);
    sleep(1);

    erase_and_animate("Spinning up AI-powered command engine...", 20, 40, strlen("Initializing Shell-Z environment..."), 1, 32);
    sleep(1);

    erase_and_animate("", 20, 50, strlen("Spinning up AI-powered command engine..."), 1, 32);
    
    gotoxy(53, 22);
    erase_and_animate("Bootstrapping core modules...", 20, 40, strlen(""), 1, 32);
    sleep(1);

    erase_and_animate("", 20, 40, strlen("Bootstrapping core modules..."), 1, 32);

    gotoxy(45, 22);
    erase_and_animate("Linking automation layer with core modules...", 20, 40, strlen(""), 1, 32);
    sleep(1);

    erase_and_animate("Injecting terminal intelligence protocols...", 20, 50, strlen("Linking automation layer with core modules..."), 1, 32);
    sleep(2);

    erase_and_animate("Verifying developer tools and integrations...", 20, 50, strlen("Injecting terminal intelligence protocols..."), 1, 32);
    sleep(1);

    erase_and_animate("Optimizing runtime performance...", 20, 50, strlen("Verifying developer tools and integrations..."), 1, 32);
    sleep(1);

    erase_and_animate("Establishing link with GitHub & cloud services...", 20, 50, strlen("Optimizing runtime performance..."), 1, 32);
    sleep(2);

    erase_and_animate("", 20, 50, strlen("Establishing link with GitHub & cloud services..."), 1, 32);

    gotoxy(50, 22);
    erase_and_animate("System Checks Complete...", 20, 50, strlen(""), 1, 32);
    sleep(1);

    // gotoxy(53, 22);
    erase_and_animate("", 20, 50, strlen("System Checks Complete..."), 1, 32);

    gotoxy(53, 22);
    erase_and_animate("Launching Shell-Z", 20, 50, strlen(""), 1, 32);
    animate("...", 1000, 1, 32);
}

// Intro animation
void intro()
{
    // system("clear");
    clear();

    printArts();
    gotoxy(36, 9);
    animate("⚡ Welcome to the Future of Interactive Terminals! ⚡\n", 50, 0, 32);

    gotoxy(45, 11);
    BG_WHITE();
    animate(" Where commands meet intelligence..! \n", 50, 1, 30);
    printDetails();
    printf("\n");
}

// Show main menu
// void showMainMenu()
// {

//     printf("\n");
//     animate("1. Run Shell Commands\n", 20, 0, 32);
//     animate("2. AI Assistance\n", 20, 0, 32);
//     animate("3. Add-ons\n", 20, 0, 32);
//     animate("4. Automation Scripts\n", 20, 0, 32);
//     animate("5. Exit\n", 20, 0, 32);
//     animate("==============================\n", 20, 0, 32);
//     animate("Enter your choice: \n", 20, 0, 32);
// }
