#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include <stdio.h>


int adder2(int a){
  return a+2;
}

void pause_function(void){
  int x;
}

void x64_continue_in_GDB(void){
  char input[5];
  printf("If you see this message inside of GDB, congratulations!\n");
  printf("You have successful launched 'reverseGame' in GDB [press ENTER to continue].\n");
  getchar();
  system("clear");
  printf("Let's start by learning about registers.\n");
  printf("There are 16 registers that x64 uses for storing general purpose data.\n");
  printf("Some of them are special.\n");
  printf("Register %rsp points to the top of the stack. Register %rbp points to the bottom of the current frame.\n");
  printf("Registers %rdi, %rsi, %rdx and %rcx hold paramters 1..4\n");
  printf("The return value is stored in register %rax [press ENTER to continue]\n");
  getchar();
  printf("Use the p command to view the value of registers:\n");
  printf("For example, to view the contents of register %rax, type:\n");
  printf("p $rax\n");
  printf("[press Enter to continue]\n");
  getchar();
  printf("Alternatively, you can use the 'info registers' command:\n");
  printf("info registers\n");
  printf("to view the current contents of all registers.\n");
  char * try_out_adder = "Let's try out a practice problem.\n \
   Type 'disas adder2' command to view the assembly of the adder2 function.\n \
   Keep in mind that this program is not yet running.";
  char * try_out_adder2 ="So using 'p' and 'info registers' will not show you anything meaningful yet.\n \
   Press [ENTER] to continue. When you are done inspecting the code, type 'n' to move on to the next part.\n";
  printf(try_out_adder);
  printf(try_out_adder2);
  getchar();
  pause_function();
  printf("Question 1: What register holds the input parameter?\n");
  printf("Your choices are: a.) %rax; b.) rcx; c.) %rdi; or d.) %rsi\n");
  scanf("%2s", input);

  while (strcmp(input, "c")!= 0 && strcmp(input, "C")!=0){
    printf("sorry, try again!\n");
    scanf("%2s", input);
  }
  printf("Correct! The first paramater is always stored in register %rdi\n[press ENTER to continue]\n");
  getchar();
  printf("Question 2: What register will hold the return value once this function executes?\n");
  printf("Your choices are: a.) %rax; b.) rbx; c.) %rbp; or d.) %rip\n");
  scanf("%2s", input);

  while (strcmp(input,"a")!=0 && strcmp(input, "A")!=0){
    printf("sorry, try again!\n");
    scanf("%2s", input);
  }
  printf("Correct! Register %rax is used for holding the return value\n[press ENTER to continue]\n");
  getchar();
  char * second_adder_question = "Suppose %rdi contained the value $0x28 (or 40).\n\
  what will register %rax contain after this function finishes executing?\n\
  If you are having trouble understanding the assembly code, read DIS 7.1 and 7.2\n";
  printf(second_adder_question);
  scanf("%5s", input);
 
  while (strcmp(input, "0x2a")!=0 && strcmp(input, "0x2A")!=0 && strcmp(input, "42")!=0){
    printf("Sorry, try again! Take a look at DIS 7.1 and 7.2 if you are having trouble reading assembly.\n");
    scanf("%5s", input);
  }  
  printf("Great job!!\nPress [ENTER] to continue then 'n' to go on to the next part.\n");
  getchar();
  pause_function();
  system("clear");
  char * ni_adder = "Lastly, let's discuss how to examine a function instruction by instruction.\n\
  The 'ni' and 'si' executes a function instruction by instruction (instead of line by line).\n\
  Examining a function in this manner allows you to inspect the values of registers as a function runs.\n\n";
  printf(ni_adder);
  char * last_part = "For the last part of this tutorial, place a breakpoint at the adder2 function:\n\
  b adder2\n\
  Then press 'n' until you hit that breakpoint.\n \
  After that, type 'disas'. Since the function is now running, you can now print out the contents of registers\
  and examine memory.\nThe arrow indicates the instruction that is about to execute.\n";
  printf(last_part);
  char *final_message = "Try it out: type 'disas' and 'ni' in alternating steps, printing out register values\
  and examining memory as you go.\nThis is also a great time to try out the TUI interface.\n \
  When you are done exploring, type 'continue' to go back to the main menu.\n\n \
  Thanks for trying out the tutorial!\n";
  printf(final_message);
  printf("Press [ENTER] to continue\n");
  getchar();
  pause_function();

  int example = 40;
  int result = adder2(40);
 
}

void x64_tutorial(void){
  printf("In this particular tutorial, we will go over x86-64 (x64) assembly.\n");
  printf("When you are ready to get started, press ENTER to continue.\n");
  getchar();
  printf("To learn about assembly, we will use the GNU Debugger (GDB).\n");
  printf("To start GDB on reverseGame, use the command 'gdb reverseGame'.\n\n");
  printf("This will place you in the GDB prompt [press ENTER to continue].\n");
  getchar();
  system("clear");
  printf("GDB allows you to place breakpoints which will pause the execution of a program at a particular location.\n");
  printf("Try out the following:\n");
  printf("Quit this tutorial using CTRL^C and then run it in GDB using the command:\n");
  printf("gdb reverseGame\n");
  printf("Next, set a breakpoint at the function 'x64_continue_in_GDB' using the command:\n");
  printf("b x64_continue_in_GDB\n");
  printf("Let's also set a breakpoint at the function 'pause_function' using the command:\n");
  printf("b pause_function\n");
  printf("Lastly, run the 'reverseGame' executable by typing: 'r' or 'run'\n");
  printf("Press 't' then the ENTER key continuously until you see a message that looks like:\n");
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
