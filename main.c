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
  printf("Hooray, you won the game!! Give yourself a pat on the back!\n");
  return 0;
}
