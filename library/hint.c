#include "hint.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hint(char * user_string, int level){
    char * read_only = "yes";
    int result = compare_strings(user_string, read_only);
    if (result != 0)
        exit(level);
    else{
        if (level == 1)
            printf("Registers? Strings? Compare? Dive Into Systems 9.1?\n");
        else if (level == 2)
            printf("I wonder if the common instructions in 9.2 are helpful?\n");
        else if (level == 3)
            printf("How can a bit be wise? You can find mORRe on multiplication in 9.3 \n");
        else if (level == 4)
            printf("I am sure they have fact (tut)orials on conditions in 9.4\n");
        else if (level == 5)
            printf("Fibbs!\n");
        else if (level == 6)
            printf("does r_sum call itself?\n");
        else if (level == 7)
            printf("That array looks pretty random to me.\n");
        else if (level == 8)
            printf("Youre pretty close! This level deals with random matrics and sums!\n");

    }
    return;
    }
