# MLV8
## A C improvement over MBOA8

## What is MLV8
MLV8 (Mini Low-level Von Neumann 8 bit) is the C improvment and continuation of my [MBOA8](https://github.com/MOHAPY24/MBOA8) CPU Emulator.
MLV8 improves on MBOA8 by using C instead of Python for preformance, a more minimal and neuanced [instruction set](instructions.md).

## Architecture

Based on the Von Neumann architechture, where instructions and data are stored in the same memory unit. In-tern making the CPU very minimal and simple.

## Installation and Usage

Make sure you have a C compiler like `clang` or `GCC` to compile the files.

First clone the repo:
```bash
git clone https://github.com/MOHAPY24/MLV8
cd MLV8
```
Then compile the `main.c` file:
```bash
gcc main.c -o main
```
or with `clang`:
```bash
clang main.c -o main
```
then finally:

```bash
./main 
```
## IMPORTANT
To use diffrent instructions/opcodes, go to the `main.c` file and change the opcodes inside `add_opcode()` functions to the opcodes you would like to use.
According to the [instruction set](instructions.md). You may add more `add_opcode()` functions but be ware the instructions that take locations need another `add_opcode()`
after them to prevent any issues and let the next instruction work well.

Any error raised in the CPU will have a number at the end of the message, those are the error id's, see what they mean at [error classification sheet](errors.md).

## LICENSE
Licensed under the BSD-3 Clause, see more in [LICENSE](LICENSE).