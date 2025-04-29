#ifndef CUSTOM_MODULES_H
#define CUSTOM_MODULES_H

#define HISTORY_SIZE 10
#define MAX_INPUT_SIZE 1024

void show_server_details();
void show_scheduler_details();
void list_all_commands();
void help();
void show_guide();
void show_history(char history[][MAX_INPUT_SIZE], int history_index, int total_commands); // Or take params if needed
void list_scripts();
void list_models();
void who();
void list_comrades();
void list_contributors();
void alpha_exit();
// void custom_sigint_handler(int signum);

#endif
