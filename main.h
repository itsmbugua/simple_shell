#ifndef MAIN_H__
#define MAIN_H__

#include <unistd.h>

char **separate_string(char *s, char *deli);
void free_arr(char **s);
void remove_new_line(char *s);
char *get_string(char *buffer);
int count_strings(char *s, char *deli);
int execute_commands(char *command, char **envp);
void exit_application(int status);
char *find_path(char *s);
int check_errors(char *str);
void print_error(char **s, char *command);
void replace_character(char *str, char s1, char s2);
void sleep_and_exit(void);
void get_current_env(char **envp);
int check_for_space(char *s);
int verify_command(char *command);

#endif
