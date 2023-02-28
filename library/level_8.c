#include "level_8.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void level8(char * user_string){
      //Level 8 creates a matrice with 2 rows and varying lengthed columns
      //4-8.This level sums the column and has the user guess that sum.
      int first_num, second_num;
      int sum1 = 0, sum2 = 0;
      int lower = 4;
      int upper = 8;
      time_t t;
      upper = ((13 % upper)+lower);
      int **M2, i, j;

      M2 = malloc(3 * sizeof(int*));
      for (i=0; i<2;i++){
          M2[i] = malloc(upper * sizeof(int));
      }
      for (i=0; i<2;i++){
          for(j=0;j<upper;j++){
              M2[i][j] = ((13*j) % 10);
              if (j==upper-1){
                  printf("\n");
              }
          }
      }
      //dot product of row and column

      for (i=0; i<2;i++){
          for(j=0;j<upper;j++){
              if (i==0)
                  sum1 += M2[i][j];
              else
                  sum2 += M2[i][j];
              }
      }
      //printf("%d %d\n", sum1, sum2);
      if (read_two_numbers(user_string, &first_num, &second_num) !=2)
          you_lose(8);
      if ((sum1 != first_num) || (sum2 != second_num))
         you_lose(8);
      else
          pass_level();
  }
