# Semiprime Factorization

**Repository:** [progintro/hw1-mrgrewk](https://github.com/progintro/hw1-mrgrewk)

**Language:** C

## Description
This program is designed to factorize a semiprime number, which is defined as a product of exactly two prime numbers. The program takes a semiprime number as input and outputs its two prime factors if found.

> [!NOTE]
> **Prime Number:** A number greater than 1 that is divisible only by 1 and itself.

## How to compile and run the program

**_The code is designed to be compiled and run on Linux-based systems._**

### Compiling

Navigate to the directory containing `factor.c` and run the following command to compile the program:

```
gcc -O3 -Wall -Wextra -Werror -o factor factor.c -lm
```

> [!IMPORTANT]
> Make sure the 32-bit gcc development tools are installed
 
 If they are not installed, you can install them by running:
 ```
 gcc -O3 -Wall -Wextra -Werror -pedantic -o rsa rsa.c
 ```

### Running

The program expects one command-line argument in the format:

```
./factor <semiprime>
```

Where `<semiprime>` is the number to be factorized, and it must be a semiprime number. The program will output the two prime factors of the semiprime.

### Test Case

You can use the following test case to ensure that the program is running as expected:

**Input:**
```
1000000003
```

**Expected Output:**
```
Factors: 7 142857143
```

## Error Handling

If the program is executed with invalid arguments or inputs, it will terminate with an error message and return an exit code of 1.

### Examples of error cases:
1. **No input given:**
    ```
    $ ./factor
    Usage: ./factor <semiprime>
    $ echo $?
    1
    ```

2. **Input is not a valid semiprime:**
    ```
    $ ./factor 8
    Error: Could not factorize the semiprime or given number is not a semiprime
    $ echo $?
    1
    ```

### Exit Codes

- **0:** Successful execution.
- **1:** Invalid arguments or input constraints violated.