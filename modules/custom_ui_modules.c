#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/custom_ui_modules.h"
#include "../include/utilities.h"

/* Method to show multi-threaded http server details when invoked */
void show_server_details()
{
    system("clear");
    ART_CYAN();
    gotoxy(45, 5);
    printf(" _   _  _______   _______ _____ \n");
    gotoxy(45, 6);
    printf("| \\ | ||  ___\\ \\ / /_   _/  ___|\n");
    gotoxy(45, 7);
    printf("|  \\| || |__  \\ V /  | | \\ `--. \n");
    gotoxy(45, 8);
    printf("| . ` ||  __| /   \\  | |  `--. \\\n");
    gotoxy(45, 9);
    printf("| |\\  || |___/ /^\\ \\_| |_\\/__/ /\n");
    gotoxy(45, 10);
    printf("\\_| \\_/\\____/\\/   \\/\\___/\\____/ \n");
    RESET();

    gotoxy(19, 15);
    BG_CYAN();
    animate(" A lightweight, multi-threaded HTTP server built for speed, simplicity, and structured logging. \n", 35, 1, 30);
    RESET();

    shell_usleep(600000);

    gotoxy(39, 18);
    animate(" Here's more about\033[1;33m Nexis\033[1;36m - Light but Powerful! \n", 35, 1, 36);

    YELLOW();
    BOLD();
    gotoxy(33, 20);
    printf("Status                :  ");
    gotoxy(33, 21);
    printf("Thread Pool           :  ");
    gotoxy(33, 22);
    printf("Root Directory        :  ");
    gotoxy(33, 23);
    printf("Log File              :  ");
    gotoxy(33, 24);
    printf("Supported Methods     :  ");
    gotoxy(33, 25);
    printf("Supported MIME Types  :  ");
    shell_usleep(400000);
    gotoxy(58, 20);
    animate("not Running", 85, 1, 36);
    shell_usleep(400000);
    gotoxy(58, 21);
    animate("not Active (Max 10 connections available)", 85, 1, 36);
    shell_usleep(400000);
    gotoxy(58, 22);
    animate("/static", 85, 1, 36);
    shell_usleep(400000);
    gotoxy(58, 23);
    animate("/User/alpha/alpha/Shell-Z/server/logs/server.log\n", 85, 1, 36);
    shell_usleep(200000);
    gotoxy(58, 24);
    animate("GET, POST, PUT, DELETE", 85, 1, 36);
    shell_usleep(400000);
    gotoxy(58, 25);
    animate("- text/html", 85, 1, 36);
    gotoxy(58, 26);
    animate("- text/css", 85, 1, 36);
    gotoxy(58, 27);
    animate("- application/javascript", 85, 1, 36);
    gotoxy(58, 28);
    animate("- image/png", 85, 1, 36);
    gotoxy(58, 29);
    animate("- image/jpeg", 85, 1, 36);
    gotoxy(58, 30);
    animate("- image/gif", 85, 1, 36);
    gotoxy(58, 31);
    animate("- image/x-icon\n", 85, 1, 36);
    YELLOW();
    BOLD();
    gotoxy(33, 33);
    printf("Features              :  ");
    gotoxy(58, 33);
    animate("- Static file serving", 65, 1, 36);
    gotoxy(58, 34);
    animate("- Multi-threaded request handling", 65, 1, 36);
    gotoxy(58, 35);
    animate("- Logging with timestamped entries", 65, 1, 36);
    gotoxy(58, 36);
    animate("- Custom error handling (404)", 65, 1, 36);
    gotoxy(58, 37);
    animate("- File-based request handling", 65, 1, 36);
    shell_usleep(600000);
    gotoxy(41, 39);
    BG_CYAN();
    animate(" Use 'alpha start server' to run the HTTP server.", 90, 1, 33);
    RESET();
    printf("\n");
}

/* Method to show process scehduler algorithm analyzer details when invoked */
void show_scheduler_details()
{
    clear();
    ART_GREEN();
    gotoxy(40, 3);
    printf(" _____      _              _      _______ _ _       \n");
    gotoxy(40, 4);
    printf("/  ___|    | |            | |    |___  (_) | |      \n");
    gotoxy(40, 5);
    printf("\\ `--.  ___| |__   ___  __| |______ / / _| | | __ _ \n");
    gotoxy(40, 6);
    printf(" `--. \\/ __| '_ \\ / _ \\/ _` |______/ / | | | |/ _` |\n");
    gotoxy(40, 7);
    printf("/\\__/ / (__| | | |  __/ (_| |    ./ /__| | | | (_| |\n");
    gotoxy(40, 8);
    printf("\\____/ \\___|_| |_|\\___|\\__,_|    \\_____/_|_|_|\\__,_|\n");
    RESET();

    gotoxy(20, 10);
    animate("An advance tool to streamline the evaluation of process scheduling algorithms, showcasing execution", 20, 1, 32);
    gotoxy(20 + strlen("An advance tool to streamline the evaluation of process scheduling algorithms, showcasing execution") / 2 - 15, 11);
    animate("timelines and metrics.", 20, 1, 32);
    gotoxy(39, 18);
    animate(" Here's more about Schedzilla - Analyze Scheduling Algorithms! \n", 35, 1, 32);
    GREEN();
    BOLD();
    gotoxy(33, 20);
    printf("Status                :  ");
    gotoxy(33, 21);
    printf("Root Directory        :  ");
    gotoxy(33, 22);
    printf("Supported Algorithms  :  ");
    shell_usleep(200000);
    gotoxy(33 + strlen("Status                :  "), 20);
    animate("not Active", 45, 1, 32);
    gotoxy(33 + strlen("Status                :  "), 21);
    animate("/scheduler", 45, 1, 32);
    gotoxy(33 + strlen("Status                :  "), 22);
    animate("FCFS - First Come First Serve.", 45, 1, 32);
    gotoxy(33 + strlen("Status                :  "), 23);
    animate("SJF  - Shortest Job First.", 45, 1, 32);
    gotoxy(33 + strlen("Status                :  "), 24);
    animate("RR   - Round Robin.", 45, 1, 32);
    GREEN();
    BOLD();
    gotoxy(33, 26);
    printf("Supported Features    :  ");
    gotoxy(33 + strlen("Status                :  "), 26);
    animate("- Detailed Performance Metrics.", 45, 1, 32);
    gotoxy(33 + strlen("Status                :  "), 27);
    animate("- Process Scheduling.", 45, 1, 32);
    gotoxy(33 + strlen("Status                :  "), 28);
    animate("- Real-time Data Analysis.", 45, 1, 32);
    GREEN();
    BOLD();
    gotoxy(33, 30);
    printf("Metrics               :  ");
    gotoxy(33 + strlen("Status                :  "), 30);
    animate("- Completion Time", 45, 1, 32);
    gotoxy(33 + strlen("Status                :  "), 31);
    animate("- Turnaround Time", 45, 1, 32);
    gotoxy(33 + strlen("Status                :  "), 32);
    animate("- Process Waiting Time", 45, 1, 32);
    gotoxy(32, 39);
    animate(" Use 'alpha run scheduler' to run the Scheduling Algorithms Analyzer.", 90, 1, 32);
    RESET();
    printf("\n");
}

/* Method to list all the commands that Shell-Z supports */
void list_all_commands()
{
    system("clear");
    ART_BLUE();
    gotoxy(38, 2);
    printf(" _____ _          _ _       ______                     _ \n");
    gotoxy(38, 3);
    printf("/  ___| |        | | |      | ___ \\                   | |\n");
    gotoxy(38, 4);
    printf("\\ `--.| |__   ___| | |______| |_/ / ___   __ _ _ __ __| |\n");
    gotoxy(38, 5);
    printf(" `--. \\ '_ \\ / _ \\ | |______| ___ \\/ _ \\ / _` | '__/ _` |\n");
    gotoxy(38, 6);
    printf("/\\__/ / | | |  __/ | |      | |_/ / (_) | (_| | | | (_| |\n");
    gotoxy(38, 7);
    printf("\\____/|_| |_|\\___|_|_|      \\____/ \\___/ \\__,_|_|  \\__,_|\n");
    RESET();

    shell_usleep(400000);
    gotoxy(36, 9);
    BG_BLUE();
    animate(" From basics to Shell-Z exclusives — ", 85, 1, 30);
    RESET();
    BG_BLUE();
    animate("it's all on ShellBoard! \n", 35, 1, 30);
    RESET();
    shell_usleep(600000);
    gotoxy(25, 12);
    animate("Shell-Z supports all the Linux/MacOS commands. Here's the list of most common ones.", 65, 1, 34);
    shell_usleep(750000);
    CYAN();
    BOLD();
    gotoxy(30, 14);
    printf("ls            :  ");
    gotoxy(30, 15);
    printf("cd            :  ");
    gotoxy(30, 16);
    printf("pwd           :  ");
    gotoxy(30, 17);
    printf("mkdir         :  ");
    gotoxy(30, 18);
    printf("rmdir         :  ");
    gotoxy(30, 19);
    printf("rm            :  ");
    gotoxy(30, 20);
    printf("cp            :  ");
    gotoxy(30, 21);
    printf("mv            :  ");
    gotoxy(30, 22);
    printf("cat           :  ");
    gotoxy(30, 23);
    printf("echo          :  ");
    gotoxy(30, 24);
    printf("touch         :  ");
    gotoxy(30, 25);
    printf("clear         :  ");
    gotoxy(47, 14);
    animate("list current directory contents", 65, 1, 33);
    gotoxy(47, 15);
    animate("Change directory", 65, 1, 33);
    gotoxy(47, 16);
    animate("Print working directory (path)", 65, 1, 33);
    gotoxy(47, 17);
    animate("Create a new directory", 65, 1, 33);
    gotoxy(47, 18);
    animate("Remove a directory", 65, 1, 33);
    gotoxy(47, 19);
    animate("Remove files or directories\n", 65, 1, 33);
    gotoxy(47, 20);
    animate("Copy files and directories\n", 65, 1, 33);
    gotoxy(47, 21);
    animate("Move or rename files\n", 65, 1, 33);
    gotoxy(47, 22);
    animate("Concatenate and display file contents\n", 65, 1, 33);
    gotoxy(47, 23);
    animate("Print messages\n", 65, 1, 33);
    gotoxy(47, 24);
    animate("Create empty files\n", 65, 1, 33);
    gotoxy(47, 25);
    animate("Clear the terminal screen\n", 65, 1, 33);
    shell_usleep(400000);
    gotoxy(55, 27);
    BG_BLUE();
    animate(" Shell-Z Exclusives \n", 95, 1, 30);
    RESET();
    CYAN();
    BOLD();
    gotoxy(30, 29);
    printf("alpha show server details       :  ");
    gotoxy(30, 30);
    printf("alpha start server              :  ");
    gotoxy(30, 31);
    printf("alpha show scheduler details    :  ");
    gotoxy(30, 32);
    printf("alpha run scheduler             :  ");
    gotoxy(30, 33);
    printf("alpha list scripts              :  ");
    gotoxy(30, 34);
    printf("alpha list --all                :  ");
    gotoxy(30, 35);
    printf("alpha list history              :  ");
    gotoxy(30, 36);
    printf("alpha show guide                :  ");
    gotoxy(30, 37);
    printf("alpha list models               :  ");
    gotoxy(30, 38);
    printf("alpha who                       :  ");
    gotoxy(65, 29);
    animate("show web server details", 65, 1, 33);
    gotoxy(65, 30);
    animate("run the Nexis development server", 65, 1, 33);
    gotoxy(65, 31);
    animate("show scheduler details", 65, 1, 33);
    gotoxy(65, 32);
    animate("run the scheduler", 65, 1, 33);
    gotoxy(65, 33);
    animate("list all the automation scripts that Shell-Z supports", 65, 1, 33);
    gotoxy(65, 34);
    animate("list all Shell-Z commands", 65, 1, 33);
    gotoxy(65, 35);
    animate("list previous 10 commands", 65, 1, 33);
    gotoxy(65, 36);
    animate("a brief tour to Shell-Z", 65, 1, 33);
    gotoxy(65, 37);
    animate("list down all the AI models that Shell-Z supports", 65, 1, 33);
    gotoxy(65, 38);
    animate("a brief intro of 'alpha' - the core dependency of Shell-Z\n", 65, 1, 33);
}

/* Method to show a detailed guide about Shell-Z. */
void help()
{
    clear();
    BOLD();
    GREEN();
    gotoxy(35, 3);
    animate("Welcome to \033[1;33mShell-Z\033[0;32m — Your AI-Enhanced Terminal Experience", 60, 1, 32);
    shell_usleep(300000);
    gotoxy(10, 5);
    printf("\033[1;32mPurpose:\033[0m");
    gotoxy(15, 6);
    animate("Shell-Z blends classic Unix commands with intelligent automation and modern tooling.", 60, 1, 32);
    shell_usleep(300000);
    gotoxy(10, 8);
    printf("\033[1;32mCore Commands:\033[0m");
    gotoxy(15, 9);
    printf("alpha show server details      :  Displays Nexis HTTP server info");
    gotoxy(15, 10);
    printf("alpha start server             :  Launch Nexis for handling HTTP requests");
    gotoxy(15, 11);
    printf("alpha show scheduler details   :  View Process Scheduler insights");
    gotoxy(15, 12);
    printf("alpha run scheduler            :  Run the Scheduler Analysis tool");
    gotoxy(15, 13);
    printf("alpha list scripts             :  View available automation scripts");
    gotoxy(15, 14);
    printf("alpha list all commands        :  Full list of Shell-Z commands");
    gotoxy(15, 15);
    printf("alpha list history             :  Show previously executed commands");
    gotoxy(15, 16);
    printf("alpha guide                    :  Brief intro of Shell-Z's capabilities");
    gotoxy(15, 17);
    printf("alpha list models              :  Show available AI interaction models");
    gotoxy(15, 18);
    printf("alpha who                      :  Learn about 'alpha' — Shell-Z's core module");
    shell_usleep(300000);
    gotoxy(10, 20);
    printf("\033[1;32mFeatures:\033[0m");
    gotoxy(15, 21);
    printf("- Multi-threaded HTTP server (Nexis)");
    gotoxy(15, 22);
    printf("- Process Scheduling Algorithms Analyzer");
    gotoxy(15, 23);
    printf("- Real-time Logging");
    gotoxy(15, 24);
    printf("- Automation Script Execution");
    gotoxy(15, 25);
    printf("- ShellBoard Command Palette");
    shell_usleep(300000);
    gotoxy(10, 27);
    printf("\033[1;32mAI Interaction:\033[0m");
    gotoxy(15, 28);
    animate("Use the 'alpha ask <your-query>' format to interact with integrated AI models.", 60, 1, 32);
    gotoxy(15, 29);
    animate("Supported models can be listed via: 'alpha list models'", 60, 1, 32);
    shell_usleep(300000);
    gotoxy(10, 31);
    printf("\033[1;32mAdd-ons & Utilities:\033[0m");
    gotoxy(15, 32);
    printf("- Nexis Web Server");
    gotoxy(15, 33);
    printf("- Scheduling Analyzer");
    gotoxy(15, 34);
    printf("- ShellBoard (graphical command palette)");
    gotoxy(15, 35);
    printf("- Alpha AI Core Integration");
    shell_usleep(300000);
    gotoxy(10, 37);
    printf("\033[1;32mQuick Tip:\033[0m");
    gotoxy(15, 38);
    animate("Start by exploring ShellBoard with 'alpha list --all' or ask something with 'alpha ask'.", 60, 1, 32);
    gotoxy(21, 40);
    animate("Shell-Z isn't just a terminal — it's a smart assistant inside your shell!\n", 60, 1, 33);
    RESET();
}

/* Method to list the last 10 commands */
void show_history(char history[][MAX_INPUT_SIZE], int history_index, int total_commands)
{
    clear();
    GREEN();
    gotoxy(50, 3);
    animate(" Shell-Z remembers everything...👀 ", 60, 1, 32);
    gotoxy(44, 5);
    animate("Here's the list of last (10) commands", 35, 1, 32);
    int count = total_commands < HISTORY_SIZE ? total_commands : HISTORY_SIZE;
    int start = (history_index - count + HISTORY_SIZE) % HISTORY_SIZE;
    for (int i = 0; i < count; i++)
    {
        int index = (start + i) % HISTORY_SIZE;
        gotoxy(49, 13 + i);
        printf("%d. ", i + 1);
        animate(history[index], 50, 0, 32);
    }
    printf("\n\n\n");
}

/* Method to list all the automation scripts that Shell-Z Offers */
void list_scripts()
{
    clear();
    ART_BLUE();
    gotoxy(25, 3);
    printf("  ___        _                        _   _               _____           _       _       \n");
    printf(" / _ \\      | |                      | | (_)             /  ___|         (_)     | |      \n");
    printf("/ /_\\ \\_   _| |_ ___  _ __ ___   __ _| |_ _  ___  _ __   \\ `--.  ___ _ __ _ _ __ | |_ ___ \n");
    printf("|  _  | | | | __/ _ \\| '_ ` _ \\ / _` | __| |/ _ \\| '_ \\   `--. \\/ __| '__| | '_ \\| __/ __|\n");
    printf("| | | | |_| | || (_) | | | | | | (_| | |_| | (_) | | | | /\\__/ / (__| |  | | |_) | |_\\__ \\\n");
    printf("\\_| |_/\\__,_|\\__\\___/|_| |_| |_|\\__,_|\\__|_|\\___/|_| |_| \\____/ \\___|_|  |_| .__/\\__|___/\n");
    printf("                                                                           | |            \n");
    printf("                                                                           |_|            \n");
    RESET();

    gotoxy(22, 12);
    animate("Below is the list of automation scripts available in Shell-Z to enhance your terminal experience.", 25, 1, 34);
    gotoxy(22, 14);
    CYAN();
    UNDERLINE();
    animate("Commands", 45, 1, 34);
    gotoxy(22, 16);
    WHITE();
    BOLD();
    printf("alpha git init");
    gotoxy(22, 17);
    printf("alpha react init");
    gotoxy(22, 18);
    printf("alpha next init");
    gotoxy(22, 19);
    printf("alpha install");
    gotoxy(22, 20);
    printf("alpha fetch github profile");
    gotoxy(22, 21);
    printf("alpha setup full-stack");
    gotoxy(22, 22);
    printf("alpha clone all");
    gotoxy(22, 23);
    printf("alpha setup python env");
    gotoxy(22, 24);
    printf("alpha setup Dockerfile");
    WHITE();
    UNDERLINE();
    gotoxy(55, 14);
    animate("Description", 45, 1, 34);
    gotoxy(55, 16);
    animate("Initialize a local git repository and connect with the cloud repository.", 30, 1, 37);
    gotoxy(55, 17);
    animate("Initialize a React JS Project in prefered directory.", 30, 1, 37);
    gotoxy(55, 18);
    animate("Initialize a Next JS Project in prefered directory.", 30, 1, 37);
    gotoxy(55, 19);
    animate("Install developer tools.", 30, 1, 37);
    gotoxy(55, 20);
    animate("Fetch a Github user profile details.", 30, 1, 37);
    gotoxy(55, 21);
    animate("Setup a full-stack project directory structure.", 30, 1, 37);
    gotoxy(55, 22);
    animate("Clone all the repositories of a github profile.", 30, 1, 37);
    gotoxy(55, 23);
    animate("Setup python virtual environment for development.", 30, 1, 37);
    gotoxy(55, 24);
    animate("Create and setup a Dockerfile.\n", 30, 1, 37);
}

/* A breif and to the point version of 'help' method */
void show_guide()
{
    clear();
    BOLD();
    GREEN();
    gotoxy(55, 3);
    animate("Shell-Z Quick Guide", 50, 1, 32);
    shell_usleep(200000);
    gotoxy(35, 5);
    printf("\033[1;32mAlpha Commands:\033[0m");
    gotoxy(40, 6);
    printf("alpha start server       :  Start Nexis HTTP server");
    gotoxy(40, 7);
    printf("alpha run scheduler      :  Launch scheduler analyzer");
    gotoxy(40, 8);
    printf("alpha list scripts       :  View automation scripts");
    gotoxy(40, 9);
    printf("alpha list all commands  :  Show all Shell-Z commands");
    shell_usleep(200000);
    gotoxy(35, 11);
    printf("\033[1;32mAI Interaction:\033[0m");
    gotoxy(40, 12);
    printf("alpha ask <query>        :  Talk to integrated AI");
    gotoxy(40, 13);
    printf("alpha list models        :  View supported AI models");
    shell_usleep(200000);
    gotoxy(35, 15);
    printf("\033[1;32mTips:\033[0m");
    gotoxy(40, 16);
    printf("- Use 'ShellBoard' for command exploration");
    gotoxy(40, 17);
    printf("- Type 'alpha who' to get to know about 'alpha'");
    shell_usleep(200000);
    gotoxy(34, 19);
    animate("Shell-Z = Commands + Automation + AI — Right in your terminal!", 60, 1, 33);
    RESET();
}

/* Method to list all the AI models (when invoked) that Shell-Z supports. */
void list_models()
{
    clear();
    gotoxy(42, 7);
    BG_WHITE();
    animate(" Here's the list of models that Shell-Z supports! ", 45, 1, 30);
    RESET();
    UNDERLINE();
    gotoxy(42 + 0, 10);
    animate("- chatGPT by OpenAI", 35, 1, 37);
    UNDERLINE();
    gotoxy(42 + 0, 12);
    animate("- Deepseek-V3 by DeepseekAI", 35, 1, 37);
    UNDERLINE();
    gotoxy(42 + 0, 14);
    animate("- Perplexity by PerplexityAI", 35, 1, 37);
    UNDERLINE();
    gotoxy(42 + 0, 16);
    animate("- Claude-Sonnet by Anthropic", 35, 1, 37);
    UNDERLINE();
    gotoxy(42 + 0, 18);
    animate("- Gemini by Google", 35, 1, 37);
    UNDERLINE();
    gotoxy(42 + 0, 20);
    animate("- Grok by xAI", 35, 1, 37);
    UNDERLINE();
    gotoxy(42 + 0, 22);
    animate("- Co-pilot by Microsoft", 35, 1, 37);
}

/* Method to Give a Brief Intro of alpha when invoked using 'alpha who' */
void who()
{
    clear();
    ART_GREEN();
    gotoxy(47, 3);
    printf("         _           _             \n");
    gotoxy(47, 4);
    printf("        | |         | |            \n");
    gotoxy(47, 5);
    printf("  __ _  | |  _ __   | |__     __ _ \n");
    gotoxy(47, 6);
    printf(" / _` | | | | '_ \\  | '_ \\   / _` |\n");
    gotoxy(47, 7);
    printf("| (_| | | | | |_) | | | | | | (_| |\n");
    gotoxy(47, 8);
    printf(" \\__,_| |_| | .__/  |_| |_|  \\__,_|\n");
    gotoxy(47, 9);
    printf("            | |                    \n");
    gotoxy(47, 10);
    printf("            |_|                    \n");
    RESET();

    gotoxy(47, 12);
    BG_WHITE();
    animate(" alpha! ", 180, 1, 30);
    RESET();
    shell_usleep(300000);
    animate(" - Your Terminal Assistant.", 45, 1, 33);
    shell_usleep(300000);
    gotoxy(52, 15);
    animate("What exactly is alpha ?", 150, 1, 32);
    gotoxy(22, 17);
    animate("\033[1;33malpha\033[1;32m is the intelligent terminal assistant at the heart of \033[1;30;47m Shell-Z! \033[0m\033[1;32m designed to elevate the", 40, 1, 32);
    gotoxy(46, 18);
    animate("the traditional command-line experience.", 65, 1, 32);
    shell_usleep(300000);
    gotoxy(46, 21);
    BG_WHITE();
    animate(" Here's what you should know about alpha! ", 45, 1, 30);
    RESET();
    shell_usleep(300000);
    gotoxy(36, 24);
    animate("- The intelligent core of Shell-Z.", 65, 1, 33);
    shell_usleep(300000);
    gotoxy(36, 25);
    animate("- Empowering Shell-Z with smart features and extended capabilities.", 65, 1, 33);
    shell_usleep(300000);
    gotoxy(36, 26);
    animate("- More than a tool — alpha is your command-line co-pilot.", 65, 1, 33);
    shell_usleep(300000);
    gotoxy(36, 27);
    animate("- Handles automation, AI-assisted tasks, and productivity enhancements.", 65, 1, 33);
    shell_usleep(300000);
    gotoxy(36, 28);
    animate("- Bridging the gap between traditional shells and next-gen terminal experiences.", 65, 1, 33);
    shell_usleep(300000);
    gotoxy(36, 29);
    animate("- Making Shell-Z not just powerful, but personal.", 65, 1, 33);
    shell_usleep(300000);
    gotoxy(36, 30);
    animate("- Built for Developers. Designed for Efficiency!\n", 100, 1, 33);
}

/* Method to List the Comrades. Comrades - Team Members / Developers */
void list_comrades()
{
    clear();
    ART_RED();
    gotoxy(28, 6);
    printf(" _____                      _____ ________  _________  ___ ______ _____ _____ \n");
    gotoxy(28, 7);
    printf("|_   _|                    /  __ \\  _  |  \\/  || ___ \\/ _ \\|  _  \\  ___/  ___|\n");
    gotoxy(28, 8);
    printf("  | | ___  __ _ _ __ ___   | /  \\/ | | | .  . || |_/ / /_\\ \\ | | | |__ \\ `--. \n");
    gotoxy(28, 9);
    printf("  | |/ _ \\/ _` | '_ ` _ \\  | |   | | | | |\\/| ||    /|  _  | | | |  __| `--. \\\n");
    gotoxy(28, 10);
    printf("  | |  __/ (_| | | | | | | | \\__/\\ \\_/ / |  | || |\\ \\| | | | |/ /| |___/\\__/ /\n");
    gotoxy(28, 11);
    printf("  \\_/\\___|\\__,_|_| |_| |_|  \\____/\\___/\\_|  |_/\\_| \\_\\_| |_/___/ \\____/\\____/ \n");
    RESET();

    gotoxy(42, 14);
    BG_RED();
    animate(" Meet the Comrades! ", 120, 1, 30);
    RESET();
    shell_usleep(300000);
    animate(" - The minds behind Shell-Z.", 50, 1, 31);
    shell_usleep(750000);
    gotoxy(32, 18);
    animate("- Ashna Jamal", 140, 1, 31);
    shell_usleep(400000);
    gotoxy(38, 19);
    animate("Undergraduate Computer Science Student at FAST National University.", 45, 1, 33);
    shell_usleep(350000);
    gotoxy(38, 20);
    animate("Github", 140, 1, 31);
    BOLD();
    RED();
    printf("    : ");
    RESET();
    gotoxy(38 + strlen("Github    : "), 20);
    animate(" https://github.com/ashnajamal21", 35, 1, 33);
    shell_usleep(300000);
    gotoxy(38, 21);
    animate("Linkedin", 120, 1, 31);
    BOLD();
    RED();
    printf("  : ");
    RESET();
    gotoxy(38 + strlen("Linkedin  : "), 21);
    animate(" https://linkedin.com/in/ashnajamal", 35, 1, 33);
    shell_usleep(700000);
    gotoxy(32, 24);
    animate("- Ayesha Javed", 140, 1, 31);
    shell_usleep(400000);
    gotoxy(38, 25);
    animate("Undergraduate Computer Science Student at FAST National University.", 45, 1, 33);
    shell_usleep(350000);
    gotoxy(38, 26);
    animate("Github", 140, 1, 31);
    BOLD();
    RED();
    printf("    : ");
    RESET();
    gotoxy(38 + strlen("Github    : "), 26);
    animate(" https://github.com/AyeshaJaved04", 35, 1, 33);
    shell_usleep(300000);
    gotoxy(38, 27);
    animate("Linkedin", 120, 1, 31);
    BOLD();
    RED();
    printf("  : ");
    RESET();
    gotoxy(38 + strlen("Linkedin  : "), 27);
    animate(" https://linkedin.com/in/aayeshajaved", 35, 1, 33);
    shell_usleep(700000);
    gotoxy(32, 30);
    animate("- Krrish Kumar", 140, 1, 31);
    shell_usleep(400000);
    gotoxy(38, 31);
    animate("Undergraduate Computer Science Student at FAST National University.", 45, 1, 33);
    shell_usleep(350000);
    gotoxy(38, 32);
    animate("Github", 140, 1, 31);
    BOLD();
    RED();
    printf("    : ");
    RESET();
    gotoxy(38 + strlen("Github    : "), 32);
    animate(" https://github.com/codewithalphadotcom", 35, 1, 33);
    shell_usleep(300000);
    gotoxy(38, 33);
    animate("Linkedin", 120, 1, 31);
    BOLD();
    RED();
    printf("  : ");
    RESET();
    gotoxy(38 + strlen("Linkedin  : "), 33);
    animate(" https://linkedin.com/in/krrishkumar", 35, 1, 33);
    shell_usleep(300000);
    gotoxy(38, 34);
    animate("Contact", 120, 1, 31);
    BOLD();
    RED();
    printf("   : ");
    RESET();
    gotoxy(38 + strlen("Contact   : "), 34);
    animate(" alpha@codewithalpha.com\n", 35, 1, 33);
    shell_usleep(600000);
}

/* Method to list the role of every individual comrade i.e. role of each individual in the team */
void list_contributors()
{
    clear();
    ART_GREEN();
    gotoxy(37, 2);
    printf(" _____             _        _ _           _                 \n");
    gotoxy(37, 3);
    printf("/  __ \\           | |      (_) |         | |                \n");
    gotoxy(37, 4);
    printf("| /  \\/ ___  _ __ | |_ _ __ _| |__  _   _| |_ ___  _ __ ___ \n");
    gotoxy(37, 5);
    printf("| |    / _ \\| '_ \\| __| '__| | '_ \\| | | | __/ _ \\| '__/ __|\n");
    gotoxy(37, 6);
    printf("| \\__/\\ (_) | | | | |_| |  | | |_) | |_| | || (_) | |  \\__ \\\n");
    gotoxy(37, 7);
    printf(" \\____/\\___/|_| |_|\\__|_|  |_|_.__/ \\__,_|\\__\\___/|_|  |___/\n");
    RESET();

    gotoxy(27, 9);
    BG_WHITE();
    animate(" Meet the minds behind Shell-Z! ", 85, 1, 32);
    RESET();
    shell_usleep(300000);
    animate(" — The architects of command, control, and innovation.", 40, 1, 32);
    int x = 9;
    gotoxy(27 - x, 12);
    UNDERLINE();
    animate("Ayesha Javed", 110, 1, 37);
    gotoxy(30 - x, 14);
    animate("• Core Architect & Shell Designer", 45, 1, 31);
    animate(" - Designs the core structure of Shell-Z, command parser, and", 45, 1, 32);
    gotoxy(30 + strlen("Core Architect & Shell Designer") + 4 - x, 15);
    animate(" overall shell logic.", 40, 1, 32);
    gotoxy(30 - x, 16);
    animate("• Automation Scripts Developer   ", 45, 1, 31);
    animate(" - Develops shell-based automation scripts and task handlers", 45, 1, 32);
    gotoxy(30 + strlen("Automation & CLI Scripts Developer") + 1 - x, 17);
    animate(" that enhance productivity.", 40, 1, 32);
    gotoxy(30 - x, 18);
    animate("• Terminal UI & Animation", 45, 1, 31);
    gotoxy(38 - x, 19);
    animate("Designer", 45, 1, 31);
    gotoxy(30 + strlen("• Terminal UI & Animation    ") + 2 - x, 18);
    animate(" - Responsible for visuals, layouts, and smooth animations using", 45, 1, 32);
    gotoxy(30 + strlen("Automation & CLI Scripts Developer") + 1 - x, 19);
    animate(" ANSI/ASCII arts.", 40, 1, 32);
    gotoxy(30 - x, 20);
    animate("• Documentation & Help System", 45, 1, 31);
    gotoxy(38 - x, 21);
    animate("Developer", 45, 1, 31);
    gotoxy(30 + strlen("• Terminal UI & Animation    ") + 2 - x, 20);
    animate(" - Maintains help commands, manual pages, and overall project", 45, 1, 32);
    gotoxy(30 + strlen("Automation & CLI Scripts Developer") + 1 - x, 21);
    animate(" documentation.", 40, 1, 32);
    gotoxy(27 - x, 23);
    UNDERLINE();
    animate("Ashna Jamal", 110, 1, 23);
    gotoxy(30 - x, 25);
    animate("• Process Scheduling Analyst", 45, 1, 31);
    gotoxy(42 - x, 26);
    animate("&", 45, 1, 31);
    gotoxy(34 - x, 27);
    animate("Performance Engineer", 40, 1, 31);
    gotoxy(30 + strlen("• Terminal UI & Animation    ") + 2 - x, 25);
    animate(" - Designs and implements CPU scheduling algorithms analyzer,", 45, 1, 32);
    gotoxy(30 + strlen("Automation & CLI Scripts Developer") + 1 - x, 26);
    animate(" benchmarking their performance, and visualizing scheduling metrics.", 40, 1, 32);
    gotoxy(27 - x, 29);
    UNDERLINE();
    animate("Krrish Kumar", 110, 1, 23);
    gotoxy(30 - x, 31);
    animate("• Feature Integration & Module", 45, 1, 31);
    gotoxy(42 - x, 32);
    animate("Handler", 40, 1, 31);
    gotoxy(30 + strlen("• Terminal UI & Animation    ") + 2 - x, 31);
    animate(" - Integrates additional features like the web server, process", 45, 1, 32);
    gotoxy(30 + strlen("Automation & CLI Scripts Developer") + 1 - x, 32);
    animate(" scheduling algorithms analyzer, and manages modularity.", 40, 1, 32);
    gotoxy(30 - x, 33);
    animate("•   AI Integration Engineer", 45, 1, 31);
    gotoxy(30 + strlen("• Terminal UI & Animation    ") + 2 - x, 33);
    animate(" - Integrated AI modules into Shell-Z to enable intelligent command", 45, 1, 32);
    gotoxy(30 + strlen("Automation & CLI Scripts Developer") + 1 - x, 34);
    animate(" interpretation and interactive responses.\n\n\n", 40, 1, 32);
}

void alpha_exit()
{
    extern int g_enable_animations;

    printf("\n\n");

    if (g_enable_animations)
    {
        // --- Animated Mode ---
        printf("\t\t\t\t\t\t");
        animate("Thank you for using Shell-Z.\n\n", 40, 1, 32);

        printf("\t\t");
        animate("Interested in contributing? Check out the GitHub Repository: ", 40, 1, 32);
        // Animate the link separately to give it color
        animate("\033[1;34mhttps://github.com/AyeshaJaved04/Shell-Z\033[0m", 40, 1, 34);
        animate("\n", 40, 1, 32);

        printf("\t\t\t\t\t  ");
        animate("Together, let's make Shell-Z even better!\n", 40, 1, 32);
    }
    else
    {
        // --- Simple Mode ---
        printf("\t\t\t\t\t\t");
        printf("Thank you for using Shell-Z.\n\n");

        printf("\t\t");
        printf("Interested in contributing? Check out the GitHub Repository: ");
        // Print only the link in blue using ANSI codes
        printf("\033[1;34mhttps://github.com/AyeshaJaved04/Shell-Z\033[0m\n");

        printf("\t\t\t\t\t  ");
        printf("Together, let's make Shell-Z even better!\n");
    }
}

// int main()
// {

//     show_scheduler_details();
//     return 0;
// }