/***Reverse Engineering Game
  (c) Suzanne J. Matthews, United States Military Academy
      suzanne.matthews@westpoint.edu
  Inspired by the Binary Bomb (Stanford University)
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library/level_admin.h"
#include "library/level_8.h"
#include "library/level_7.h"
#include "library/level_6.h"
#include "library/level_5.h"
#include "library/level_4.h"
#include "library/level_3.h"
#include "library/level_2.h"
#include "library/level_1.h"
/*
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
*/
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
