#ifndef _HELP_H_
#define _HELP_H_

#include <stdio.h>

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

void help_gdb(void){
  printf("This is the help menu for GDB basics\n");
  printf("while this guide will attempt to be as assembly language agnostic as possible, please note that may not always be possible\n");
  printf("We will not be discussing assembly basics here. If you are interested in learning more about a particular assembly language, visit the help menus for those, or the Dive into Systems textbook\n");
  printf("If you want to view the help info for 64-bit x86 assembly, run:\n");
  printf("./reverseGame help x64\n");
  printf("If you want to view the help info for 64-bit ARM assembly, run:\n");
  printf("./reverseGame help a64\n");
  printf("If you want to view the help info for 32-bit x86 assembly, run:\n");
  printf("./reverseGame help x86\n");
  printf("If you want to view the help info for the binary game executable, run:\n");
  printf("./reverseGame help me!\n");
  printf("Press [ENTER] to continue reading the help menu for 64-bit ARM. To quit and change your option, type 'q'\n");
  pause_function();

  printf("Let's begin with a discussion of common GDB commands:\n");
  printf("Start/Quit GDB:\n");
  printf("\t [r]un: runs the program. Typing 'run' during a program's execution will restart it\n");
  printf("\t [q]uit: quits the program.\n\n");

  printf("To load the reverseGame in GDB, type:\n\tgdb reverseGame\n");
  printf("If the game started successfully, you should land in a prompt that looks like\n");
  printf("\t(gdb)\n\n");

  printf("To run the reverseGame in GDB, type (in the gdb prompt):\n\t(gdb) run\n");
  printf("You can also run it with a solutions file (solutions.txt) in GDB:\n\t(gdb) run solutions.txt\n\n");  
  printf("Typing 'q' at the GDB prompt will exit GDB and return you to the command line. This means any and all breakpoints you may have set will be lost\n");
  printf("[Press ENTER to continue, q to quit]\n");
  pause_function();

  printf("Setting/Deleting Breakpoints\n");
  printf("\t [b]reak [func]: sets a breakpoint (assigned a number) at function [func]\n");
  printf("\t [b]reak *[addr]: sets a breakpoint (assigned a number) at code address [addr]\n");
  printf("\t [d]elete {#}: deletes all breakpoints (if a number is specified, deletes only that breakpoint)\n\n");
  printf("We would recommend you set a breakpoint at each level in the game.\n");
  printf("For example, to set a breakpoint at level0, type:\n\t(gdb) b level0\n\n");

  printf("Please note that if you quit GDB, all breakpoints will be automatically lost.\n\n");
  printf("[Press ENTER to continue, q to quit]\n");
  pause_function();

  printf("Navigating through Assembly Programs\n");
  printf("You can view the assembly for any function at any given time by using the command:\n");
  printf("\t [disas]semble {func}: disassemble function {func}\n");
  printf("As an example, the following command will display the assembly for level 0:\n");
  printf("\t (gdb) disas level0\n");
  printf("Notice that you must be at the GDB prompt for this command to work.\n\n");
 
  printf("The following navigation commands will ONLY work when the program is running:\n");
  printf("\t [disas]semble: disassemble current function (depends on where instruction pointer is)\n");
  printf("\t [s]tep[i] {#}: executes the next instruction. If a number is specified, executes that number of instructions.\n");  
  printf("\t [n]ext[i] {#}: Like si, but will proceed through function calls, not step into them.\n");
  printf("In general, we recommend you use nexti and use stepi only when necessary\n\n");
 
  printf("The following GDB commands commonly skip several instructions ");
  printf("and moves the instruction pointer to the next breakpoint if one exists.\n"); 
  printf("Be careful using these instructions, as they can cause you to execute a program too far!\n");  
  printf("\t [n]ext: executes the next line of CODE (do not confuse this with nexti!)\n");
  printf("\t [c]ontinue {num}: continues to next {num} loop iterations\n\n");
  printf("[Press ENTER to continue, q to quit]\n");
  pause_function();

  printf("Examining Data during a program's execution (only works when a program is running):\n");
  printf("\t [p]rint $reg: prints contents of register reg (note that for x86/x64, don't include the %%)\n");
  printf("\t [p]rint /x $reg: print the contents of register reg in hex\n");
  printf("\t [x] /x $reg: examine (or dereference) register reg and print out the result in hex\n");
  printf("\t [x] /s $reg: examine (or dereference) register reg and print out the result as a string\n");
  printf("\t [x] /s addr: examine (or dereference) the address and print out the result as a string\n");
  printf("\t [x] /64bx $sp: examine the 64 hex bytes prior to address in register sp\n\n");
  printf("You can also get a view of the current value of all registers by using the info registers command:\n");
  printf("\t (gdb) info registers\n");
  printf("\t or\n");
  printf("\t (gdb) i r\n\n");
  printf("Some helpful tips:\n");
  printf("\t GDB uses C format descriptors. So, to display output as a char use /c, as an integer use /d\n");
  printf("\t GDB display formats are sticky. So, if you type a command like p /x $reg, the next time you type p $reg2");
  printf(", it will likely display reg2's content in hex format\n");
  printf("\t In general, we recommend you view register values in hex format.");
  printf(" If you suspect a register contains an address, use x to dereference it and view the associated value.\n");
  printf("\t If you get garbage/nonsensical output when printing/examining, ");
  printf("try changing the format descriptor.\n");
  printf("\t The instruction pointer's location is represented by an arrow (=>) in GDB.\n");
  printf("\t Remember, the instruction pointer (=>) shows the NEXT instruction to execute!\n");
  printf("\t If a register does not contain the value you expect, make sure the instruction pointer is where you expect.");
  pause_function();
  printf("As a final set of tips, we recommend that you:\n");
  printf("\t Set breakpoints at each level\n");
  printf("\t Advance the instruction pointer right before a function call, and inspect registers/stack locations that may contain parameters\n");
  printf("\t Use nexti to proceed through function calls. Only use stepi if you want to trace through the function.\n");
  printf("\t NEVER trace through a standard C function (usually contains \"@plt\" in its name)\n"); printf("\t Instead, remember you can always look up what a standard C function looks like online\n");
  printf("\t In general, advance through a program using nexti. Use stepi only as needed\n");
  printf("\t Inspect the register that is reserved for the return value immediately after a function call.\n\n"); 
  printf("Have fun and happy string hunting!\n");
  exit(0);
}

void help_a64(void){
  printf("This is the help menu for 64-bit ARM assembly (i.e., a64)\n");
  printf("If you want to view the help menu for 64-bit x86 assembly, run:\n");
  printf("./reverseGame help x64\n");
  printf("Press [ENTER] to continue reading the help menu for 64-bit ARM. To quit and change your option, type 'q'\n");
  pause_function();

  printf("Let's start by learning about registers.\n");
  printf("There are 31 registers that a64 uses for storing general purpose data.\n");
  printf("They are: x0 ... x30\n");
  printf("Each of the above registers hold 64-bit (8 byte) data\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("The compiler will typically use the component registers of the main registers when handling data smaller that 8 bytes\n");
  printf("The component of a main register can be accessed by replacing the first letter ('x') of the register's name with an 'w'. So the 32-bit component of x0 is w0\n");
  printf("Note that pointer or address data always will be stored in the 8-byte registers on 64-bit systems\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("The compiler reserves particular registers for special purposes.\n");
  printf("Registers sp and x29 are reserved for stack management.\n\tsp points to the top of the stack\n\tregister x29 points to the bottom of the current frame.\n");
  printf("The return address to the calling function is stored in register x30 (note that this is different from the return value!)\n");
  printf("Registers x0..x7 (w0...w7) are used to hold function parameters\n"); 
  printf("\tAny function's parameters beyond 8 are then stored on call stack\n");
  printf("Register x0 (w0) holds the returned value from a function (if one exists) after a function call\n");
  printf("Register pc is the instruction pointer (i.e., program counter). It is not a general purpose register.\n"); 
  printf("[PRESS ENTER TO CONTINUE, q to quit].\n");
  pause_function();

  printf("Prior to a function being called, its parameters are loaded (in order) into the needed registers.\n");
  printf("An example, consider a function foo with the declaration int foo(int a, long b, char *c)\n");
  printf("Suppose the main function calls foo:\n foo(aval,bval,cstring);\n");
  printf("Prior to the function call, main will have instructions that load:\n\t the argument aval into register w0 (ints are 32 bits)\n");
  printf("\t the argument bval into register x1 (longs are 64 bits)\n");
  printf("\t the base address of cstring into register x2 (pointers/addresses take up 64-bits)\n");
  printf("All of the above instructions will occur prior to the function call to foo (which looks something like the following):\n");
  printf("bl addr <foo>\n");

  printf("Immediately after the call to foo, the return value will be stored in register w0 (since foo is a function that returns an int, a 32-bit value)\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("When completing the binary game, we recommend that you always look for function calls, and inspecting the registers corresponding to the arguments immediately prior to the function call, and the return value immediate after the function call.\n\n");
  printf("To learn more about ARM 64-bit assembly, we recommend that you read Dive into Systems Chapter 9\n");
  printf("https://diveintosystems.org/book/C9-ARM64/index.html\n");
  exit(0);
}

void help_x64(void){
  printf("This is the help info for 64-bit x86 (i.e., x86-64 or x64)\n");
  printf("If you want to view the help info for 32-bit x86, run:\n");
  printf("./reverseGame help x86\n");
  printf("If you want to view the help info for 64-bit ARM, run:\n");
  printf("./reverseGame help a64\n");
  printf("Press [ENTER] to continue reading the help info for 64-bit x86. To quit and change your option, type 'q'\n");
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
  printf("Prior to the function call, main will have instructions that load:\n\t the argument aval into register %%edi (ints are 32 bits)\n");
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

void help_x86(void){
  printf("This is the help info for 32-bit x86 Assembly\n");
  printf("If you want to view the help info for 64-bit x86, run:\n");
  printf("./reverseGame help x64\n");
  printf("If you want to view the help menu for 64-bit ARM, run:\n");
  printf("./reverseGame help a64\n");
  printf("(Sorry, we do not support 32-bit ARM)\n");
  printf("Press [ENTER] to continue reading the help info for x86. To quit and change your option, type 'q'\n");
  pause_function();

  printf("Let's start by learning about registers.\n");
  printf("There are 8 registers that x86 uses for storing general purpose data.\n");
  printf("They are: %%eax, %%ebx, %%ecx, %%edx, %%edi, %%esi, %%esp, and %%ebp\n");
  printf("Each of the above registers hold 32-bit (4 byte) data\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("For the first for registers, the compiler will typically use component registers of the main registers when handling data smaller that 4 bytes\n");
  printf("To access the component register of a particular register, the following format is used:\n");
  printf("\t The 16-bit component can be accessed by referring to the last two letters in the register's name. So the 16-bit component of %%eax is %%ax\n");
  printf("\t The least significant byte is accessed like the 16-bit component, but the last letter is instead an 'l'. So the 8-bit component of %%eax is %%al\n");
  printf("Note that pointer or address data always will be stored in the 4-byte registers on 32-bit systems\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("The compiler reserves particular registers for special purposes.\n");
  printf("Registers %%esp and %%ebp are reserved for stack management.\n \t%%esp points to the top of the stack\n\tregister %%ebp points to the bottom of the current frame.\n");
  printf("Since registers %%esp and %%ebp hold stack addresses, their component registers are typically not used\n");
  printf("Function parameters are stored on the stack, at an offset of %%ebp+8 and above, typically in 4 byte increments.\n");
  printf("(The return address is stored at %ebp+4)\n");
  printf("Register %%eax holds the returned value from a function (if one exists) after a function call\n");
  printf("Register %%eip is the instruction pointer. It is not a general purpose register.\n"); 
  printf("[PRESS ENTER TO CONTINUE, q to quit].\n");
  pause_function();

  printf("Prior to a function being called, its parameters are loaded (in reverse order) onto the top of the stack.\n");
  printf("An example, consider a function foo with the declaration int foo(int a, long b, char *c)\n");
  printf("Suppose the main function calls foo:\n foo(aval,bval,cstring);\n");
  printf("Prior to the function call, main will have instructions that load:\n\t the argument aval into stack location (%%esp) (ints are 32 bits)\n");
  printf("\t the argument bval into stack location (%%esp + 4) (longs are also 32 bits)\n");
  printf("\t the base address of cstring into location (%%esp + 8) (pointers/addresses take up 32-bits)\n");
  printf("All of the above instructions will occur prior to the function call to foo (which looks something like the following):\n");
  printf("call foo<addr>\n");

  printf("Immediately after the call to foo, the return value will be stored in register %%eax (since foo is a function that returns an int)\n");
  printf("[PRESS ENTER TO CONTINUE, q to quit]\n");
  pause_function();

  printf("When completing the binary game, we recommend that you always look for function calls, and inspecting the registers corresponding to the arguments immediately prior to the function call, and the return value immediate after the function call.\n\n");
  printf("To learn more about x86 assembly, we recommend that you read Dive into Systems Chapter 8\n");
  printf("https://diveintosystems.org/book/C8-IA32/index.html\n");
  exit(0);
}

void help_game(void){
  system("clear");
  printf("Here are some helpful tips to get started\n");
  printf("\t The game has ten levels named level0 .. level9\n");
  printf("\t To pass each level, you need to figure out the secret string associated with that level\n\n");
  printf("We recommend...\n");
  printf("\t Running the game in GDB\n"); 
  printf("\t Setting breakpoints at each level\n"); 
  printf("\t tracing through the assembly slowly\n\n");

  printf("Here are a sample set of commands to get you started:\n");
  printf("\t $ gdb reverseGame\n");
  printf("\t (gdb) b level0\n");
  printf("\t (gdb) run\n");
  printf("\t (gdb) disas level0\n");
  printf("[Press ENTER to get more guidance, q to quit]\n");
  pause_function();

  printf("To prevent having to retype answers, you can store your solutions in a textfile:\n");
  printf("\t $ cat ans.txt\n");
  printf("\t guess\n");
  printf("\t $ ./reverseGame ans.txt\n\n");
  printf("You can also run the binary game in GDB with the answer file:\n");
  printf("\t $ gdb reverseGame\n");
  printf("\t (gdb) r ans.txt\n\n");
  printf("[Press ENTER to continue, q to quit]\n");
  pause_function();

  printf("Need more help? View our help menu by typing ./reverseGame help!\n");
  help_menu();
  printf("[Press ENTER to continue, q to quit]\n");
  pause_function();
  printf("\nLastly, the free textbook, Dive into Systems (diveintosystems.org) has full chapters on x86, x64, and A64 assembly.\n");
  printf("Good luck, and happy string hunting.!\n");
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

  if (strcmp(option, "me!")==0){
    help_game();
  }
  if (strcmp(option, "gdb")==0){
    help_gdb();
  }
  else if (strcmp(option, "x64")==0){
    help_x64();
  }
  else if (strcmp(option, "x86")==0){
    help_x86();
  }
  else if (strcmp(option, "a64")==0){
    help_a64();
  }
  else{
    fprintf(stderr, "invalid option!\n");
    exit(1);
  }
}





#endif 
