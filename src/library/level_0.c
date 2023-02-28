#include "level_0.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level0(char * user_string){
    int input;
    int num;
    num = sscanf(user_string, "%d", &input);
    if (input == 1337)
        pass_level(0);
    else
        you_lose(0);
}
