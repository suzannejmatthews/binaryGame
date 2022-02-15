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
FILE *infile;
int main(int argc, char * argv[]){
    
  char input[100]; //all strings are less than 100 chars
  char text[100][100];
  int i = 0;

  if (argc == 1){
    infile = stdin;
  }
  else if (argc == 2) {
    if (!(infile = fopen(argv[1], "r"))) {
        printf("%s: Could not process %s\n", argv[0], argv[1]);
        exit(0);
        }
    infile = fopen(argv[1], "r");
    while(fgets(text[i], 100, infile)){
        i++;
    }
  }


  printf("Welcome to the reverse engineering game and tutorial!\n");
  printf("Would you like to enter tutorial mode or game mode? ([t]utorial/[g]ame): ");
  if (argc == 1) {
      fgets(input,100,stdin);
      if (strncmp(input, "t\n",3)!=0 && strncmp(input, "g\n", 3)!=0) die_with_message("invalid option. please enter t or g", 1);
      if (strncmp(input, "t\n", 3)==0){
        run_tutorial();
        printf("Would you like to try out the game? [y/n] ");
        fgets(input,100,stdin);
        while (strncmp(input, "y\n", 3)!=0 && strncmp(input, "n\n", 3)!=0) {
          fprintf(stderr, "invalid option. please enter y or n ");
          fgets(input,100,stdin);
        }
        if (strncmp(input, "n\n",3)==0)
          return 0;     
      }
  }
  printf("The game has nine levels (level1...level9) that you ");
  printf("need to reverse engineer to win the game!\n");
  printf("To pass each level, you need to figure out the secret string ");
  printf("you need to enter. Good luck and happy hacking!\n");
  printf("Also, if you would like to pass an answer file,");
  printf("call the function normally followed by your answer file\n");
  printf("Example: ./reverseGame ans.txt\n");
  printf("where ans contains:\n");
  printf("  ans1\n");
  printf("  ans2\n");
  if (i >= 1){
    level1(text[0]);
  }
  else{
      fgets(input,100,stdin);
      level1(input);
  }

  printf("Good job with level 1! How about level 2?\n");
  if (i >= 2){
    level2(text[1]);
  }
  else{
      fgets(input,100,stdin);
      level2(input);
  }


  printf("Excellent work with level 2! Onwards to level 3!\n");

  if (i >= 3){
    level3(text[2]);
  }
  else{
      fgets(input,100,stdin);
      level3(input);
  }

  printf("Wow, you're really getting the hang of this!\n");
  printf("Ready for a challenge? Try level 4!\n");
  if (i >= 4){
    level4(text[3]);
  }
  else{
      fgets(input,100,stdin);
      level4(input);
  }

  printf("Awesome work!! Now for the toughest challenge yet...\n");
  printf("Pass level 5!\n");
  if (i >= 5){
    level5(text[4]);
  }
  else{
      fgets(input,100,stdin);
      level5(input);
  }

  printf("Can you overcome 6?!\n");
  if (i >= 6){
    level6(text[5]);
  }
  else{
      fgets(input,100,stdin);
      level6(input);
  }
  printf("Good job with level 6! Ready for level 7?\n"); 
  if (i >= 7){
    level7(text[6]);
  }
  else{
      fgets(input,100,stdin);
      level7(input);
  }

  printf("That wasn't too bad. Level 8 here you come!\n");
  if (i >= 8){
    level8(text[7]);
  }
  else{
      fgets(input,100,stdin);
      level8(input);
  }

  printf("Level 9 isn't bad at all!\n");
  if (i >= 9){
    level9(text[8]);
  }
  else{
      fgets(input,100,stdin);
      level9(input);
  }
  printf("Hooray, you won the game!! Give yourself a pat on the back!\n");
  return 0;
}
