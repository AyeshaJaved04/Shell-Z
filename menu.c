#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include "include/menu.h"
#include "include/utilities.h"

// --- Key Codes (ANSI for arrows) ---
#define KEY_ESC '\033'
#define KEY_BRACKET '['
#define KEY_UP 'A'
#define KEY_DOWN 'B'
#define KEY_ENTER '\n'

// --- Menu Configuration ---
#define NUM_OPTIONS 2
#define START_Y 14 // Vertical start position

// --- Terminal Control (for macOS/Linux) ---
static struct termios old_tio, new_tio;

void init_termios(int echo)
{
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~ICANON;
    if (echo)
    {
        new_tio.c_lflag |= ECHO;
    }
    else
    {
        new_tio.c_lflag &= ~ECHO;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

void reset_termios(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

const char *options[NUM_OPTIONS] = {
    "Shell-Z",
    "Shell-Z-mation (Shell-Z with animations)"};


// --- Border & UI Functions ---

void draw_border()
{
    int rows, cols;
    get_terminal_size(&rows, &cols);
    GREEN();
    for (int i = 1; i <= cols; i++)
    {
        gotoxy(i, 1);
        printf((i == 1 || i == cols) ? "+" : "=");
        gotoxy(i, rows);
        printf((i == 1 || i == cols) ? "+" : "=");
    }
    for (int i = 2; i < rows; i++)
    {
        gotoxy(1, i);
        printf("|");
        gotoxy(cols, i);
        printf("|");
    }
    RESET();
    fflush(stdout);
}

void display_instructions()
{
    int rows, cols;
    get_terminal_size(&rows, &cols);
    const char *nav_text = "Use arrow keys to navigate";
    const char *sel_text = "Press ENTER to select";
    gotoxy((cols - strlen(nav_text)) / 2, rows - 3);
    GREEN();
    printf("%s", nav_text);
    RESET();
    gotoxy((cols - strlen(sel_text)) / 2, rows - 2);
    printf("%s", sel_text);
    RESET();
}

void display_menu(int current_selection)
{
    int rows, cols;
    get_terminal_size(&rows, &cols); // Get current terminal dimensions

    // --- main menu options (centered) ---
    for (int i = 0; i < NUM_OPTIONS; i++)
    {
        // Total length includes option text + 4 characters for decoration (e.g. "> ... <")
        int full_text_length = strlen(options[i]) + 4;
        int start_x = (cols - full_text_length) / 2;

        if (start_x < 1)
            start_x = 1; // Prevent drawing on the border

        gotoxy(start_x, START_Y + i * 2);

        if (i == current_selection)
        {
            BOLD();
            WHITE();
            printf("> %s <", options[i]);
            RESET();
        }
        else
        {
            GREEN();
            printf("  %s  ", options[i]);
            RESET();
        }
    }

    // --- "Current Selection" text below the menu (centered) ---
    char selection_text[128];
    sprintf(selection_text, "Current Selection: %s", options[current_selection]);

    int text_len = strlen(selection_text);
    int text_x = (cols - text_len) / 2;
    int text_y = START_Y + NUM_OPTIONS * 5 + 2; // place it below the menu

    if (text_x < 1)
        text_x = 1;

    // To prevent leftover characters when text changes
    gotoxy(1, text_y);
    printf("\033[2K"); // ANSI code to erase the entire line


    gotoxy(text_x, text_y);
    WHITE();
    BOLD();
    printf("%s", selection_text);
    RESET();

    gotoxy(1, 1);
    fflush(stdout);
}

int show_start_menu()
{
    int current_selection = 0;
    int choice = -1;
    char ch;

    init_termios(0);
    atexit(reset_termios);
    printf("\033[?25l"); // Hide cursor

    clear();
    draw_border();
    display_instructions();
    display_menu(current_selection);

    while (choice == -1)
    {
        ch = getchar();
        if (ch == KEY_ESC)
        {
            if (getchar() == KEY_BRACKET)
            {
                switch (getchar())
                {
                case KEY_UP:
                    current_selection = (current_selection - 1 + NUM_OPTIONS) % NUM_OPTIONS;
                    break;
                case KEY_DOWN:
                    current_selection = (current_selection + 1) % NUM_OPTIONS;
                    break;
                }
            }
        }
        else if (ch == KEY_ENTER)
        {
            choice = current_selection;
        }

        if (choice == -1)
        {
            // redraw the menu content instead of clearing the whole screen, which is more efficient.
            display_menu(current_selection);
        }
    }

    reset_termios();
    printf("\033[?25h"); // Show cursor
    clear();
    gotoxy(1, 1);

    return choice;
}