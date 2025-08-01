#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../include/utilities.h"

// Make the global variable from main.c available here
extern int g_enable_animations;

void get_terminal_size(int *rows, int *cols)
{
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
    {
        *rows = 24;
        *cols = 80;
    }
    else
    {
        *rows = ws.ws_row;
        *cols = ws.ws_col;
    }
}

void animate(const char *text, int delay, int styleCode, int colorCode)
{
    // If animations are disabled, print text directly and IGNORE ALL STYLING.
    if (!g_enable_animations)
    {
        printf("%s", text);
        fflush(stdout);
        return;
    }

    // If animations are enabled, proceed with the original logic.
    printf("\033[%d;%dm", styleCode, colorCode);
    fflush(stdout);

    while (*text)
    {
        printf("%c", *text);
        fflush(stdout);
        usleep(delay * 1000);
        text++;
    }

    printf("\033[0m");
    fflush(stdout);
}

void erase_and_animate(const char *newText, int eraseDelay, int printDelay, int lengthToErase, int styleCode, int colorCode)
{
    if (!g_enable_animations)
    {
        printf("%s", newText);
        fflush(stdout);
        return;
    }

    for (int i = 0; i < lengthToErase; i++)
    {
        printf("\b \b");
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
    animate(text, delay, 0, 32);
    printf("\n");
}

void gotoxy(int x, int y) { printf("\033[%d;%dH", y, x); }
void ui_black()     { if (g_enable_animations) printf("\033[0;30m"); }
void ui_red()       { if (g_enable_animations) printf("\033[0;31m"); }
void ui_green()     { if (g_enable_animations) printf("\033[0;32m"); }
void ui_yellow()    { if (g_enable_animations) printf("\033[0;33m"); }
void ui_blue()      { if (g_enable_animations) printf("\033[0;34m"); }
void ui_magenta()   { if (g_enable_animations) printf("\033[0;35m"); }
void ui_cyan()      { if (g_enable_animations) printf("\033[0;36m"); }
void ui_white()     { if (g_enable_animations) printf("\033[0;37m"); }
void ui_bold()      { if (g_enable_animations) printf("\033[1m"); }
void ui_underline() { if (g_enable_animations) printf("\033[4m"); }
void ui_reversed()  { if (g_enable_animations) printf("\033[7m"); }
void ui_bg_black()  { if (g_enable_animations) printf("\033[40m"); }
void ui_bg_red()    { if (g_enable_animations) printf("\033[41m"); }
void ui_bg_green()  { if (g_enable_animations) printf("\033[42m"); }
void ui_bg_yellow() { if (g_enable_animations) printf("\033[43m"); }
void ui_bg_blue()   { if (g_enable_animations) printf("\033[44m"); }
void ui_bg_magenta(){ if (g_enable_animations) printf("\033[45m"); }
void ui_bg_cyan()   { if (g_enable_animations) printf("\033[46m"); }
void ui_bg_white()  { if (g_enable_animations) printf("\033[47m"); }


void bold_green_text(const char *text) {
    printf("\033[1;32m%s", text);
}


void shell_sleep(unsigned int seconds) { if (g_enable_animations) { sleep(seconds); } }
void shell_usleep(useconds_t useconds) { if (g_enable_animations) { usleep(useconds); } }