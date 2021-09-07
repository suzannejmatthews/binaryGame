/***Reverse Engineering Game
  (c) Suzanne J. Matthews, United States Military Academy
      suzanne.matthews@westpoint.edu
  Inspired by the Binary Bomb (Stanford University)
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void you_lose(int level){
  printf("You lose the game!\n");
  exit(level);
}

void pass_level(){
  printf("You passed the level!!\n");
}

int compare_strings(char * x, char *y){
  int length = strlen(x);
  x[length-1] =0;
  return strcmp(x,y);
}

int read_three_numbers(char * string, int * f, int *s, int *r){
  return sscanf(string, "%d %d %d", f, s, r);
}

int read_two_numbers(char *string, int *f, int *s){
  return sscanf(string, "%d %d", f, s);
}

void level1(char * user_string){
  char * read_only = "Assembly is so cool!";
  int result = compare_strings(user_string, read_only);
  if (result != 0)
    you_lose(1);
  else
    pass_level();
  return;
}

void level2(char * user_string){
  int first, second,temp;
  if(read_two_numbers(user_string, &first, &second) != 2)
    you_lose(2);
  temp = first-second;
  if (temp == 42)
    pass_level();
  else
    you_lose(2);
}

void level3(char * user_string){
  int first,second,result,temp;
  if (read_three_numbers(user_string, &first, &second, &result) != 3)
    you_lose(3);
  if (first > 10 || second > 10)
    you_lose(3);
  temp = first*5+second;
  if (result == temp)
    pass_level();
  else
    you_lose(3);
}

void level4(char * user_string){
  int start, end, result=1, temp;
  if (read_two_numbers(user_string, &start, &end)!=2)
    you_lose(4);
  if (start > 5)
    you_lose(4);
  temp=start;
  while (temp > 0){
    result *= temp;
    temp--;
  }
  if (result == end)
    pass_level();
  else
    you_lose(4);
}

void level5(char * user_string){
  int start, end, result, temp1=0, temp2=1,i;
  if (read_two_numbers(user_string, &start, &end)!=2)
    you_lose(5);
  if (start < 2 && start > 10)
    you_lose(5);
  i = 1; 
  while (i < start){
    result = temp1+temp2;
    temp1 = temp2;
    temp2 = result;
    i++;
  }
  if (result != end)
    you_lose(5);
  else
    pass_level();
}

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

void level7(char * user_string){
    //Level 7 initializes an array of size 10. Then, it fills the array
    //with random numbers between 0 and 9. After that, the user must figure
    //out the sum of the left and right halves of the array and return 
    //that to the screen.
    int my_array[10];
    int i;
    int left_sum = 0;
    int right_sum = 0;
    int first_num, second_num;
    if (read_two_numbers(user_string, &first_num, &second_num) !=2)
        you_lose(7);

    time_t t;
    srand((unsigned) time(&t));
    for (i=0;i<10;i++){
        my_array[i] = (rand() % 10);
    }
    for (i=0;i<5;i++){
        left_sum += my_array[i];
        right_sum += my_array[i+5];
    }
    if ((first_num != left_sum) || (second_num != right_sum))
        you_lose(7);
    else
        pass_level();
    }

void level8(char * user_string){
    //Level 8 creates a matrice with 2 rows and varying lengthed columns
    //4-8.This level sums the column and has the user guess that sum.
    int first_num, second_num;
    int sum1 = 0, sum2 = 0;
    if (read_two_numbers(user_string, &first_num, &second_num) !=2)
        you_lose(8);
    int lower = 4;
    int upper = 8; 
    time_t t;
    srand((unsigned) time(&t));
    upper = ((rand() % upper)+lower);
    int **M2, i, j;
    
    M2 = malloc(3 * sizeof(int*));
    for (i=0; i<2;i++){
        M2[i] = malloc(upper * sizeof(int));
    }
    for (i=0; i<2;i++){
        for(j=0;j<upper;j++){
            M2[i][j] = (rand() % 10);
           // printf("%d ",M2[i][j]); //Uncomment this to see the matrice build.
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

    
    if ((sum1 != first_num) || (sum2 != second_num))
       you_lose(8);
    else
        pass_level();
}


int main(int argc, char ** argv){
  char input[100]; //all strings are less than 100 chars

  printf("Welcome to the reverse engineering game!\n");
  printf("The game has six levels (level1...level6) that you ");
  printf("need to reverse engineer to win the game!\n");
  printf("To pass each level, you need to figure out the secret string ");
  printf("you need to enter. Good luck and happy hacking!\n");
  fgets(input, 100, stdin);
  level1(input);
  printf("Good job with level 1! How about level 2?\n");
  fgets(input,100,stdin);
  level2(input);
  printf("Excellent work with level 2! Onwards to level 3!\n");
  fgets(input,100,stdin);
  level3(input);
  printf("Wow, you're really getting the hang of this!\n");
  printf("Ready for a challenge? Try level 4!\n");
  fgets(input,100,stdin);
  level4(input);
  printf("Awesome work!! Now for the toughest challenge yet...\n");
  printf("Pass level 5!\n");
  fgets(input,100,stdin);
  level5(input);
  fgets(input, 100, stdin);
  level6(input);
  printf("Good job with level 6! Ready for level 7?\n"); 
  fgets(input, 100, stdin);
  level7(input);
  printf("That wasn't too bad. Level 8 here you come!\n");
  fgets(input, 100, stdin);
  level8(input);
  printf("Hooray, you won the game!! Give yourself a pat on the back!\n");
  return 0;
}
