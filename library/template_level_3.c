#include "level_3.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level3(char * user_string){
   int first, second, result, temp;
   if (read_three_numbers(user_string, &first, &second, &result) != 3)
       you_lose(3);
    if (first < 10 || second < 10)
        you_lose(3);
    temp = (first)1_operand(stub_level_3)2_operand(second);
               
    if (result == temp)
        pass_level();
    else
        you_lose(3);
    }

