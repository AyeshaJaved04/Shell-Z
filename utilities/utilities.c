#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../include/utilities.h"

/* Macros */
#define RESET_COLOR "\033[0m"
#define RESET()     printf("\033[0m")

#define BLACK()     printf("\033[0;30m")
#define RED()       printf("\033[0;31m")
#define GREEN()     printf("\033[0;32m")
#define YELLOW()    printf("\033[0;33m")
#define BLUE()      printf("\033[0;34m")
#define MAGENTA()   printf("\033[0;35m")
#define CYAN()      printf("\033[0;36m")
#define WHITE()     printf("\033[0;37m")

#define BOLD_GREEN_TEXT(text) printf("\033[1;32m%s", text)

#define BOLD()          printf("\033[1m")
#define UNDERLINE()     printf("\033[4m")
#define REVERSED()      printf("\033[7m")

#define BG_BLACK()      printf("\033[40m")
#define BG_RED()        printf("\033[41m")
#define BG_GREEN()      printf("\033[42m")
#define BG_YELLOW()     printf("\033[43m")
#define BG_BLUE()       printf("\033[44m")
#define BG_MAGENTA()    printf("\033[45m")
#define BG_CYAN()       printf("\033[46m")
#define BG_WHITE()      printf("\033[47m")


void animate(const char *text, int delay, int styleCode, int colorCode)
{
    printf("\033[%d;%dm", styleCode, colorCode);
    fflush(stdout);

    while (*text)
    {
        printf("%c", *text);
        fflush(stdout);
        usleep(delay * 1000);
        text++;
    }

    printf(RESET_COLOR);
    fflush(stdout);
}

void erase_and_animate(const char *newText, int eraseDelay, int printDelay, int lengthToErase, int styleCode, int colorCode)
{
    for (int i = 0; i < lengthToErase; i++)
    {
        printf("\b \b"); // erase animation
        fflush(stdout);
        usleep(eraseDelay * 1000);
    }

    animate(newText, printDelay, styleCode, colorCode);
}

void printCentered(const char *text, int delay)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int term_width = w.ws_col;
    int text_length = strlen(text);
    int padding = (term_width - text_length) / 2;

    for (int i = 0; i < padding; i++)
        printf(" ");

    fflush(stdout);

    while (*text)
    {
        printf("%c", *text);
        fflush(stdout);
        usleep(delay * 1000);
        text++;
    }

    printf("\n");
}

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}