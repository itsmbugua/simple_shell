#ifndef MAIN_H__
#define MAIN_H__

#include <unistd.h>

char **separate_string(char *s);
void free_arr(char **s);
char *remove_new_line(char *s);
int execute_commands(char *command, char *env[]);
char *get_string(void);
int count_strings(char *s);
void exit_application(pid_t child_pid, pid_t parent_pid);
char *find_path(char *s);

#endif
