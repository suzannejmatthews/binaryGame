#include "level_1.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level1(char * user_string){
    char * read_only = "stub_level_1";
    int result = compare_strings(user_string, read_only);
    //repalce with strencmp
    if (result != 0)
        you_lose(1);
    else
        pass_level();
    return;
    }
