#include "level_6.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level6(char * user_string){
      int first_num, second_num, sum_num, tmp;
      second_num = 10;
      if (read_two_numbers(user_string, &first_num, &sum_num) !=2)
          you_lose(6);
      if (first_num > second_num)
          you_lose(6);
      if ((second_num-first_num) < 5)
          you_lose(6);
      int r_sum(int a, int b){
          int result;
          if (a==b)
              return b;
          result = a;
          result += r_sum(a+1, b);
          return result;
      }
      tmp = r_sum(first_num, second_num);
      if (sum_num == tmp)
          pass_level();
      else
          you_lose(6);
  }

