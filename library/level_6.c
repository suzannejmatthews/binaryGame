#include "level_6.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void level6(char * user_string){
      //Level 6 recursively sums the values between two numbers. The user gives
      //the range of number to be summed as well as the sum of that range.
      //The difference of the numbers must be at least 5.
      int first_num, second_num, sum_num, tmp;
      if (read_three_numbers(user_string, &first_num, &second_num, &sum_num) !=3)
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
      //Eventually, this will randomy select two different numbers and
      //find the recursive sum of the range between those two numbers.

  }

