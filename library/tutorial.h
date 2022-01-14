#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include <stdio.h>

void x64_continue_in_GDB(void){
  printf("If you see this message inside of GDB, congratulations!\n");
  printf("You have successful launched 'reverseGame' in GDB [press ENTER to continue].\n")
  getchar();
  printf("Let's start by learning about registers.\n");
  printf("There are 16 registers that x64 uses for storing general purpose data.\n");
  printf("Some of them are special.\n");
  
}

void x64_tutorial(void){
  printf("In this particular tutorial, we will go over x86-64 (x64) assembly.\n");
  printf("When you are ready to get started, press ENTER to continue.\n");
  getchar();
  printf("To learn about assembly, we will use the GNU Debugger (GDB).\n");
  printf("To start GDB on reverseGame, use the command 'gdb reverseGame'.\n\n");
  printf("This will place you in the GDB prompt [press ENTER to continue].\n");
  getchar();
  printf("GDB allows you to place breakpoints which will pause the execution of a program at a particular location.\n");
  printf("Try out the following:\n");
  printf("Quit this tutorial using CTRL^C and then run it in GDB using the command:\n");
  printf("gdb reverseGame\n");
  printf("Next, set a breakpoint at the function 'x64_continue_in_GDB' using the command:\n");
  printf("b x64_continue_in_GDB\n");
  printf("Lastly, run the 'reverseGame' executable by typing: 'r' or 'run'\n");
  printf("Press the ENTER key continuously until you see a message that looks like:\n");
  printf("Breakpoint 1, 0x0000555555555349 in x64_continue_in_GDB ()\n");
  printf("Then type 'n' for 'next'\n");
  printf("Press CTRL^C now and try out the above steps.\n");
  getchar();
  x64_continue_in_GDB();
}
int run_tutorial(void){
  getchar();
  printf("Welcome to tutorial mode! [press ENTER to continue]\n");
  getchar();
  x64_tutorial();
  return 0;

}

#endif 
