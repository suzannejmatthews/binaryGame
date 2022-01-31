#include "level_7.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void level7(char * user_string){
    /*Level 7 initializes an array of size 10. Then, it fills the array 
    with numbers between 0 and 9. -> [0,1,9,4,6,3,5,0,1,1]
    After that, the user must figure out
    the sum of the left and right halves of the array and return that to the 
    screen */
    int my_array[10];
    int i;
    int left_sum = 0;
    int right_sum = 0;
    int first_num;
    int second_num;
    time_t t;
    //srand((unsigned) time(&t));
    srand((unsigned) 100);
    for (i=0;i<10;i++){
        my_array[i] = (rand() %10);
        printf("%d\n", my_array[i]);
    }
    for(i=0;i<5;i++){
        left_sum += my_array[i];
        right_sum += my_array[i+5];
    }
    
    if (read_two_numbers(user_string, &first_num, &second_num) != 2){
        you_lose(7);
    }

    else if((first_num != left_sum) || (second_num != right_sum)){
        you_lose(7);
    }
    else
        pass_level();
    }
