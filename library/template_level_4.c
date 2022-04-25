#include "level_4.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level4(char * user_string){
    int start, end, result=1, temp;
    if (read_two_numbers(user_string, &start, &end)!=2)
        you_lose(4);
    if (start<3)
        you_lose(4);
    temp=start;
    while (temp > 0){
        result *= temp;
        result += stub_level_4;
        temp--;
    }
    if (result == end)
        pass_level();
    else
        you_lose(4);
    }
