#ifndef _HELP_H_
#define _HELP_H_

#include <stdio.h>


int adder2(int a){
  return a+2;
}

void pause_function(void){
  char in;
  in = tolower(getchar());
  while (in != 'q' && in != '\n'){
    in = tolower(getchar());
  }
  if (in == 'q') {
    printf("quitting...\n");
    exit(0);
  }
  system("clear");
}

void help_x64(void){
  printf("This is the help menu for 64-bit x86 (i.e., x86-64 or x64)\n");
  printf("If you want to view the help menu for 32-bit x86, run:\n");
  printf("./reverseGame help x86\n");
  printf("If you want to view the help menu for 64-bit ARM, run:\n");
  printf("./reverseGame help a64\n");
  printf("Press [ENTER] to continue reading the help menu for 64-bit x86. To quit and change your option, type 'q'\n");
  pause_function();

  printf("Let's start by learning about registers.\n");
  printf("There are 16 registers that x64 uses for storing general purpose data.\n");
  printf("They are: %rax, %rbx, %rcx, %rdx, %rdi, %rsi, %rsp, %rbp, and %r8 ... %r15\n");
  printf("Each of the above registers hold 64-bit (8 byte) data\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("The compiler will typically use component registers of the main registers when handling data smaller that 8 bytes\n");
  printf("To access the component register of a particular register, the following format is used for the first eight registers listed above:\n");
  printf("\t The 32-bit component can be accessed by replacing the first letter ('r') with an 'e'. So the 32-bit component of %rax is %%eax\n");
  printf("\t The 16-bit component can be accessed by referring to the last two letters in the register's name. So the 16-bit component of %rax is %%ax\n");
  printf("\t The least significant byte is accessed like the 16-bit component, but the last letter is instead an 'l'. So the 8-bit component of %rax is %%al\n");
  printf("Note that pointer or address data always will be stored in the 8-byte registers on 64-bit systems\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("The compiler reserves particular registers for special purposes.\n");
  printf("Registers %rsp and %rbp are reserved for stack management.\n \t%rsp points to the top of the stack\n\tregister %rbp points to the bottom of the current frame.\n");
  printf("Since registers %rsp and %rbp hold stack addresses, their component registers are typically not used\n");
  printf("Several other general purpose registers are used to hold function parameters. Their component registers are commonly used in x64 programs\n"); 
  printf("\tRegisters %rdi, %rsi, %rdx and %rcx hold parameters 1..4\n");
  printf("\tRegisters %r8 and %r9 hold parameters 5 and 6\n");
  printf("\tAny additional parameters are then stored on call stack\n");
  printf("Register %rax holds the returned value from a function (if one exists) after a function call\n");
  printf("Register %rip is the instruction pointer. It is not a general purpose register.\n"); 
  printf("[PRESS ENTER TO CONTINUE, q to quit].\n");
  pause_function();

  printf("Prior to a function being called, its parameters are loaded (in order) into the needed registers.\n");
  printf("An example, consider a function foo with the declaration int foo(int a, long b, char *c)\n");
  printf("Suppose the main function calls foo:\n foo(aval,bval,cstring);\n");
  printf("Prior to the function call, main will have instructions that load:\n\t the argument aval into register %%eax (ints are 32 bits)\n");
  printf("\t the argument bval into register %%rsi (longs are 64 bits)\n");
  printf("\t the base address of cstring into register %%rdx (pointers/addresses take up 64-bits)\n");
  printf("All of the above instructions will occur prior to the function call to foo (which looks something like the following):\n");
  printf("call foo<addr>\n");

  printf("Immediately after the call to foo, the return value will be stored in register %%eax (since foo is a function that returns an int)\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("When completing the binary game, we recommend that you always look for function calls, and inspecting the registers corresponding to the arguments immediately prior to the function call, and the return value immediate after the function call.\n\n");
  printf("To learn more about x64 assembly, we recommend that you read Dive into Systems Chapter 7\n");
  printf("https://diveintosystems.org/book/C7-x86_64/index.html\n");
  exit(0);
}

void lowercase(char * string){
  int i;
  for (i = 0; i < 3; i++){
    string[i]=tolower(string[i]);
  }
}

void help_select(char *option){
  if (strlen(option)!=3){
    fprintf(stderr, "invalid option\n");
    exit(1);
  }

  if (strcmp(option, "gdb")==0){
    printf("help_gdb();\n");
  }
  else if (strcmp(option, "x64")==0){
    help_x64();
  }
  else if (strcmp(option, "x86")==0){
    printf("help_x86();\n");
  }
  else if (strcmp(option, "a64")==0){
    printf("help_a64();\n");
  }
  else{
    fprintf(stderr, "invalid option!\n");
    exit(1);
  }
}

void help_menu(void){
  printf("Please enter\n");
  printf("./reverseGame help [option]\n");
  printf("where option is either gdb, x64, x86, a64\n");
  printf("To review one of our informational summaries. Detailed information below\n");
  printf("[gdb] : useful GDB commands\n"); 
  printf("[x64] : x86-64 ISA summary\n");
  printf("[x86] : x86 (32-bit) ISA summary\n");
  printf("[a64] : ARM 64 ISA summary\n");
}



#endif 
