#include "level_3.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level3(char * user_string){
   int first, second, result, temp;
   if (read_three_numbers(user_string, &first, &second, &result) != 3)
       you_lose(3);
    if (first < 10)
        you_lose(3);
    temp = (first)1_operand(1stub)2_operand(second);
               
    if (result == (2stub - temp - result))
        pass_level();
    else
        you_lose(3);
    }

