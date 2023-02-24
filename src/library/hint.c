#include "hint.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hint(char * user_string, int level){
    char * read_only = "yes\n";
    int result = strcmp(user_string, read_only);
    int chapter = 9; //modify to 7 for x64, 8 for x86, 9 for a64
    if (result != 0)
        exit(level);
    else{
        if (level == 0)
            printf("(gdb) p/d $register shows you the value within a register.\n");
        if (level == 1)
            printf("Registers? Strings? Compare? Dive Into Systems %d.1?\n", chapter);
        else if (level == 2)
            printf("I wonder if the common instructions in %d.2 are helpful?\n", chapter);
        else if (level == 3)
            printf("How can a bit be wise? You can find mORRe on multiplication in %d.3 \n", chapter);
        else if (level == 4)
          printf("I am sure they have fact (tut)orials on conditions in %d.4\n", chapter);
        else if (level == 5)
            printf("Fibbs!\n");
        else if (level == 6)
            printf("does r_sum call itself?\n");
        else if (level == 7)
            printf("left half plus right half.\n");
        else if (level == 8)
            printf("Youre pretty close! This level deals with matrics and sums, simlar to before!\n");
        else if (level == 9)
            printf("Sorry, no hints here.!\n");

    }
    return;
    }
