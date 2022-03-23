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
#include "library/level_0.h"
#include "library/help.h"
#include "library/wrapper.h"
FILE *infile;

int main(int argc, char * argv[]){
    
  char input[100]; //all strings are less than 100 chars
  char text[100][100];
  int i = 0;

  if (argc == 1){
    infile = stdin;
  }
  else if (argc == 2) {
    if (strncmp(argv[1], "help", 5)==0){ 
      help_menu();
      exit(0);
    }
    if (!(infile = fopen(argv[1], "r"))) {
        printf("%s: Could not process %s\n", argv[0], argv[1]);
        exit(0);
        }
    infile = fopen(argv[1], "r");
    while(fgets(text[i], 100, infile)){
        i++;
    }
  }
  else {
    if (strncmp("help", argv[1], 4)==0){
      help_select(argv[2]);
    }
    else{
        printf("Too many inputs...\n");
        exit(0);
    }
  }


  printf("Welcome to the reverse engineering game!\n");
  printf("The game has ten levels (level0...level9) that you ");
  printf("need to reverse engineer to win the game!\n");
  printf("To pass each level, you need to figure out the secret string ");
  printf("you need to enter. Good luck and happy hacking!\n");
  printf("If you still feel lost, CTRL-C this program and type:\n");
  printf("\t ./reverseGame help me!\n");
  printf("Or\n");
  printf("\t ./reverseGame help\n");
  printf("To view our help pages\n");

  printf("What do you have for level0:\n");

  if (i >= 1){
    level0(text[0]);
  }
  else{
      fgets(input,100,stdin);
      level0(input);
  }
  printf("Level 0 wasn't too bad! I am sure you can get level 1!\n");
  if (i >= 2){
    level1(text[1]);
  }
  else{
      fgets(input,100,stdin);
      level1(input);
  }

  printf("Good job with level 1! How about level 2?\n");
  if (i >= 3){
    level2(text[2]);
  }
  else{
      fgets(input,100,stdin);
      level2(input);
  }


  printf("Excellent work with level 2! Onwards to level 3!\n");

  if (i >= 4){
    level3(text[3]);
  }
  else{
      fgets(input,100,stdin);
      level3(input);
  }

  printf("Wow, you're really getting the hang of this!\n");
  printf("Ready for a challenge? Try level 4!\n");
  if (i >= 5){
    level4(text[4]);
  }
  else{
      fgets(input,100,stdin);
      level4(input);
  }

  printf("Awesome work!! Now for the toughest challenge yet...\n");
  printf("Pass level 5!\n");
  if (i >= 6){
    level5(text[5]);
  }
  else{
      fgets(input,100,stdin);
      level5(input);
  }

  printf("Can you overcome 6?!\n");
  if (i >= 7){
    level6(text[6]);
  }
  else{
      fgets(input,100,stdin);
      level6(input);
  }
  printf("Good job with level 6! Ready for level 7?\n"); 
  if (i >= 8){
    level7(text[7]);
  }
  else{
      fgets(input,100,stdin);
      level7(input);
  }

  printf("That wasn't too bad. Level 8 here you come!\n");
  if (i >= 9){
    level8(text[8]);
  }
  else{
      fgets(input,100,stdin);
      level8(input);
  }

  printf("Level 9 isn't bad at all!\n");
  if (i >= 10){
    level9(text[9]);
  }
  else{
      fgets(input,100,stdin);
      level9(input);
  }
  printf("Hooray, you won the game!! Give yourself a pat on the back!\n");
  return 0;
}
