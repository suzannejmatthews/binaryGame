/***Reverse Engineering Game
  (c) Suzanne J. Matthews and D'Angelo Gourdine, United States Military Academy
      suzanne.matthews@westpoint.edu
  Inspired by the Binary Bomb (CMU)
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library/level_admin.h"
#include "library/level_9.h"
#include "library/level_8.h"
#include "library/level_7.h"
#include "library/level_6.h"
#include "library/level_5.h"
#include "library/level_4.h"
#include "library/level_3.h"
#include "library/level_2.h"
#include "library/level_1.h"
#include "library/tutorial.h"

int main(int argc, char ** argv){
  char input[100]; //all strings are less than 100 chars
  printf("Welcome to the reverse engineering game and tutorial!\n");
  printf("Would you like to enter tutorial mode or game mode? ([t]utorial/[g]ame): ");
  scanf("%s2", input);
  if (strncmp(input, "t", 2)!= 0 && strncmp(input, "g", 2)!=0) die_with_message("invalid option. please enter t or g", 1);
  if (strncmp(input, "t", 2) == 0){
    run_tutorial();
    printf("Would you like to try out the game? [y/n] ");
    scanf("%s2", input);
    while (strncmp(input, "y", 2)!=0 && strncmp(input, "n", 2)!= 0) {
      fprintf(stderr, "invalid option. please enter y or n ");
      scanf("%s2", input);
    }
    if (strncmp(input, "n", 2)==0)
      return 0;     
  }
  printf("The game has nine levels (level1...level9) that you ");
  printf("need to reverse engineer to win the game!\n");
  printf("To pass each level, you need to figure out the secret string ");
  printf("you need to enter. Good luck and happy hacking!\n");
  printf("P.S. Some levels involve rand(), a random number ");
  printf("generator, so you may have to modify registers \n");
  printf("with $set 'register' = 'value', depending on some condition.\n");
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
  printf("Level 9 isn't bad at all!\n");
  fgets(input, 100, stdin);
  level9(input);
  printf("Hooray, you won the game!! Give yourself a pat on the back!\n");
  return 0;
}
