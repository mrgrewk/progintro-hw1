# RSA Algorithm

**Repository:** [progintro/hw1-mrgrewk](https://github.com/progintro/hw1-mrgrewk)

**Language:** C

## Description
This program implements the RSA algorithm, a widely used cryptographic method for secure data transmission. It provides two main functionalities:

1.  **Encryption:** Encrypts a plaintext message using the RSA method.
    
2.  **Decryption:** Decrypts a ciphertext message back into plaintext.
    

The program operates on user-provided inputs, including public and private keys, and performs calculations within the constraints of the RSA algorithm.

## How to compile and run the program

**_<ins>The code is designed to be compiled and run on Linux based systems.</ins>_**

### Compiling

Navigate through the terminal to the desired directory where you would like the program to be compiled, and run the following command:

```
gcc -O3 -Wall -Wextra -Werror -pedantic -o rsa rsa.c
```
> [!IMPORTANT]
> Make sure the 32-bit gcc development tools are installed
 
 If they are not installed, you can install them by running:
 ```
 gcc -O3 -Wall -Wextra -Werror -pedantic -o rsa rsa.c
 ```

### Running

The program requires 5 command-line arguments in the format:

```
./rsa <operation> <e> <d> <p> <q>
```    

Where:

*   \<operation\>: Either enc (encryption) or dec (decryption)
    
*   \<e\>: Public exponent
    
*   \<d\>: Private exponent
    
*   \<p\>: Prime number 1
    
*   \<q\>: Prime number 2
    

Additionally, the plaintext message (for encryption) or ciphertext message (for decryption) is provided through standard input.

#### Input Constraints:

*   All integers (e, d, p, q, and the message) must be within the range \[-10^18, 10^18\].
    
*   Negative numbers are not allowed for primes p and q.
    
*   The plaintext message must be smaller than N = p \* q.
    
*   e must be coprime with ϕ(N) (Euler's totient function of N).
    
*   The product e \* d mod ϕ(N) must equal 1.
    

#### Example:

1. Encrypt a message
    ```
    $ echo 123 | ./rsa enc 13 37 11 7
    62
    ```
    
2. Decrypt a message
    ```
    $ echo 62 | ./rsa dec 13 37 11 7
    123
    ```


### Error Handling

If the program is executed with invalid arguments or inputs, it will terminate with an error message and return an exit code of 1.
 
**Examples:**

1.
```
    $ ./rsa
    Usage: ./rsa enc|dec <e> <d> <p> <q>
    $ echo $?
    1
```
    
2.
```
   $ ./rsa xyz 1 2 3 4
   First argument must be 'enc' or 'dec'
   $ echo $?
   1
```
    
3.
```
    $ ./rsa enc 1 2 4 6
    p and q must be prime
    $ echo $?
    1
```
    
4.
```
    $ echo 500 | ./rsa enc 5 173 17 19
    Message is larger than N
    $ echo $?
    1
```
    

### Exit Codes

*   0: Successful execution.
    
*   1: Invalid arguments or input constraints violated.
    

### Notes on Implementation


*   The RSA algorithm ensures security through mathematical principles, such as modular arithmetic and prime factorization.
    
*   The program handles all necessary checks to validate user inputs and RSA constraints before performing encryption or decryption.
    
*   Careful attention is given to avoid overflow or other computational errors.