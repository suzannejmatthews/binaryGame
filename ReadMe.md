<a name="readme-top"></a>



## About BinaryGame


The BinaryGame is a open-source resource designed to help students learn reverse engineering at their own pace through an iterative, guided design. The game consists of ten levels that increase in difficulty, help pages on GDB, and supports three flavors of assembly language. Modeled after concepts covered in each of the first nine sections of the Assembly chapters in the free online textbook, _Dive into Systems_, the levels are: (0) predefined C functions; (1) basic string matching; (2,3) arithmetic operations; (4,5) loops; (6) recursion; (7) arrays; (8) matrices; and (9) structs.

<p align="right">(<a href="#readme-top">back to top</a>)</p>




## Getting Started

### Prerequisites

In order to compile the BinaryGame, you must ensure that you install the latest instance of Python3 and Linux's build-essentials.
* build-essential
  ```sh
  $ sudo apt update
  $ sudo apt upgrade
  $ sudo apt install build-essential
  ```
* Python3
  ```sh
  $ sudo apt update
  $ sudo apt install python3
  ```


### Installation



* Clone the repo
   ```sh
   git clone https://github.com/suzannejmatthews/binaryGame.git
   ```

## Compilation
To create the game's executable and the object files for linking, type `make` in the `/binaryGame/src` directory. The BinaryGame executable is stored in the aforementioned directory. To clean the directory of the created object files and executable, navigate back to the `/binaryGame/src` directory and type `make clean`.


<p align="right">(<a href="#readme-top">back to top</a>)</p>



## Usage
### Reversing
To begin reverse engineering the executable, type `gdb ./reverse` within the `/binaryGame/src` directory, launching the executable in GNU's portable debugger. Type `run` to start the program in the debugger. Use various break points throughout the code to halt the execution of the program for analysis:
```sh
  $ gdb ./reverseGame
  .
  .
  .
  (gdb) break main
  Breakpoint 1 at 0x2129
  (gdb) run
  Starting program: /home/user/binaryGame/src/reverseGame
  .
  Breakpoint 1, 0x0000000008002129 in main ()
  .
  (gdb) disas
  ...
  
  ```
  ### Help Pages and Hints
  If you get stuck, access the help pages by typing `./reverseGame help me!` the `/binaryGame/src` directory, providing guidance on GDB, registers, and the game itself. Furthermore, if you get a question wrong, you can respond `yes` to the hints prompt and receive helpful information on how to solve that particular level. 


_For more information on the GNU Debugger (GDB), please refer to the [Documentation](https://linux.die.net/man/1/gdb)_



## Contact

D'Angelo Gourdine -  dangelo.gourdine@westpoint.edu

Suzanne J. Matthews - suzanne.matthews@westpoint.edu


## Acknowledgments
* [Suzanne J. Matthews, Tia Newhall, and Kevin C. Webb. _Dive into Systems_](https://diveintosystems.org/)
* [CMU's Binary Bomb Lab](http://www.cs.cmu.edu/afs/cs/academic/class/15213-s02/www/applications/labs/lab2/bomblab.html)

<p align="right">(<a href="#readme-top">back to top</a>)</p>




