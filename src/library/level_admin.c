#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hint.h"

void die_with_message(char *msg, int exit_code){
    fprintf(stderr, "%s\n", msg);
    exit(exit_code);
}
	
void you_lose(int level){
    printf("You lose the game!\n");
    printf("Would you like a hint? [yes|no]\n");
    char choice[10];
    scanf("%10s", choice);
    hint(choice, level);
    exit(level);
}

void pass_level(void){
    printf("You passed the level!! \n");
}

int compare_strings(char *x, char *y){
  int len = strlen(y);
  return strncmp(x,y,len);
}

int read_three_numbers(char * string, int * f, int *s, int *r){
    return sscanf(string, "%d %d %d", f, s, r);
}

int read_two_numbers(char *string, int *f, int *s){
    return sscanf(string, "%d %d", f, s);
}
