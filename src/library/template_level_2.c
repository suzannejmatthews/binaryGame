#include "level_2.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level2(char * user_string){
    int first, second, temp;
    if (read_two_numbers(user_string, &first, &second) != 2)
        you_lose(2);
    temp = (first)stub_level_2_1(second);
    if (temp == stub_level_2_2)
        pass_level();
    else
        you_lose(2);
    }

