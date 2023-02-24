#include "level_5.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level5(char * user_string){
    int start, end, result, temp1=0, temp2=1,i;
    if(read_two_numbers(user_string, &start, &end)!=2)
        you_lose(5);
    if (start<2 && start >10)
        you_lose(5);
    i=1;
    while (i<stub_level_5){
        result = temp1+temp2;
        temp1 = temp2;
        temp2 = result;
        i++;
    }
    if (result!=end)
        you_lose(5);
    else
        pass_level();
    }
