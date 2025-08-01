#ifndef UTILITES_H
#define UTILITES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

/* --- Unconditional Macros for ASCII Art --- */
/* These will ALWAYS apply color, used only for the Headings. */
#define ART_CYAN()   printf("\033[0;36m")
#define ART_GREEN()  printf("\033[0;32m")
#define ART_BLUE()   printf("\033[0;34m")
#define ART_RED()    printf("\033[0;31m")


/* --- Conditional Macros for UI Text --- */
/* These will call functions that only apply color if animations are enabled. */
#define clear() system("clear");

#define RESET()     printf("\033[0m") // RESET should always work to turn off art colors.

#define BLACK()     ui_black()
#define RED()       ui_red()
#define GREEN()     ui_green()
#define YELLOW()    ui_yellow()
#define BLUE()      ui_blue()
#define MAGENTA()   ui_magenta()
#define CYAN()      ui_cyan()
#define WHITE()     ui_white()

#define BOLD_GREEN_TEXT(text) bold_green_text(text) // Needs to be a function now

#define BOLD()          ui_bold()
#define UNDERLINE()     ui_underline()
#define REVERSED()      ui_reversed()

#define BG_BLACK()      ui_bg_black()
#define BG_RED()        ui_bg_red()
#define BG_GREEN()      ui_bg_green()
#define BG_YELLOW()     ui_bg_yellow()
#define BG_BLUE()       ui_bg_blue()
#define BG_MAGENTA()    ui_bg_magenta()
#define BG_CYAN()       ui_bg_cyan()
#define BG_WHITE()      ui_bg_white()

/* --- Function Declarations for UI Colors --- */
void ui_black();
void ui_red();
void ui_green();
void ui_yellow();
void ui_blue();
void ui_magenta();
void ui_cyan();
void ui_white();
void bold_green_text(const char *text);
void ui_bold();
void ui_underline();
void ui_reversed();
void ui_bg_black();
void ui_bg_red();
void ui_bg_green();
void ui_bg_yellow();
void ui_bg_blue();
void ui_bg_magenta();
void ui_bg_cyan();
void ui_bg_white();

/* --- Standard Function Declarations --- */
void animate(const char *text, int delay, int styleCode, int colorCode);
void erase_and_animate(const char *newText, int eraseDelay, int printDelay, int lengthToErase, int styleCode, int colorCode);
void printCentered(const char *text, int delay);
void gotoxy(int x, int y);
void get_terminal_size(int *rows, int *cols);

// --- Custom conditional delay functions ---
void shell_sleep(unsigned int seconds);
void shell_usleep(useconds_t useconds);

#endif