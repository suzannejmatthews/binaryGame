#ifndef level_admin_h
#define level_admin_h

void you_lose(int level);
void pass_level(void);
int compare_strings(char *x, char *y);
int read_three_numbers(char * string, int * f, int *s, int *r);
int read_two_numbers(char *string, int *f, int *s);
void die_with_message(char *str, int exit_code);
#endif
