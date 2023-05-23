#ifndef MAIN_H__
#define MAIN_H__

char **separate_string(char *s);
void free_arr(char **s);
char *remove_new_line(char *s);
int execute_commands(char *command, char *env[]);
char *get_string(void);
int count_strings(char *s);

#endif
