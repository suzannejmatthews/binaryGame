#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hint.h"

void you_lose(int level){
    printf("You lose the game!\n");
    printf("Would you like a hint? [yes|no]\n");
    char choice[100];
    fgets(choice, 100, stdin);
    hint(choice, level);
    exit(level);
}

void pass_level(){
    printf("You passed the level!! \n");
}

int compare_strings(char *x, char *y){
    int length = strlen(x);
    x[length-1] =0;
    return strcmp(x,y);
}
int read_three_numbers(char * string, int * f, int *s, int *r){
    return sscanf(string, "%d %d %d", f, s, r);
}
int read_two_numbers(char *string, int *f, int *s){
    return sscanf(string, "%d %d", f, s);
}
