# Euclidean algorithm
**Respitory:** [progintro/hw1-mrgrewk](https://github.com/progintro/hw1-mrgrewk)

**Language:** C

## Description
|This program applies the Euclidean Algorithm to find the Greatest Common Divisor of two numbers given by the user and outputs it.

## How to compile and run the program
**_<ins>The code is designed to be compiled and run on Linux based systems.</ins>_**
### Compiling
Navigate through the terminal to the prefered directory you would like the program to get compiled in and run the following command:
```bash
gcc-O3-Wall-Wextra-Werror-pedantic-o gcd gcd.c
```
> [!IMPORTANT]
> Make sure the 32-bit gcc development tools are installed.

If they are not, you can install them by running:
```bash
sudo apt-get install lib32gcc-4.8-dev
```
### Running 
**1. <ins>Start the program</ins>**

After compilation, run the program with:
```bash
./gcd <num1> <num2>
```
> Replace \<num 1\> and \<num2\> with the respective numbers you want to calculate the Greatest Common Divisor of.

> [!IMPORTANT]
> You can only enter arguments withing the range of: (-10^18)-(10^18)

*It is recomended to seperate the arguments by one space as instructed earlier, otherwise the program may show unexpected behavior.*

**2. <ins>Output</ins>**

The program outputs the result in the terminal as: gcd(\<num1\>, \<num2\>) = \<result\>

**3. <ins>Termination</ins>**

The program terminates on its own after displaying the result and returns exit code 0.

If the arguments given to the program are of incorrect type or 0 is given as a value, then the program terminates without giving a result and returns exit code 1.

*You can check the exit code's value by running:*
```bash
echo $?
```

## Example Interaction
```plaintext
 $ hostname
 linux11
 $ gcc -O3 -Wall -Wextra -Werror -pedantic -o gcd gcd.c
 $ ./gcd
 Usage: ./gcd <num1> <num2>
 $ echo $?
 1
 $ ./gcd 1
 Usage: ./gcd <num1> <num2>
 $ ./gcd 26 40
 gcd(26, 40) = 2
 $ ./gcd 26 -40
 gcd(26, -40) = 6
 $ ./gcd -40 26
 gcd(-40, 26) = 2
 $ ./gcd 999999937 999999929
 gcd(999999937, 999999929) = 1
 $ ./gcd 10000000019 20000000038
 gcd(10000000019, 20000000038) = 10000000019
 $ echo $?
 0
 $ ./gcd 0 29
 Usage: ./gcd <num1> <num2>
 $ echo $?
 1
 $ time ./gcd 8473218639530741684 3751874978312684508
 gcd(8473218639530741684, 3751874978312684508) = 4
 0.002u 0.000s 0:00.00 0.0%