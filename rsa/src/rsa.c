#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the greatest common divisor
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return llabs(a);
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string represents a valid positive integer
int is_valid_positive_integer(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}    

// Modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    if (mod <= 0) {
        printf("Error: modulus must be greater than zero\n");
        return -1;
    }

    long long result = 1;
    base = (base % mod + mod) % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 6) {
        printf("Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n");
        return 1;
    }

    // Read arguments and check if they are valid integers
    char *operation = argv[1];
    if (strcmp(operation, "enc") != 0 && strcmp(operation, "dec") != 0) {
        printf("Error: First argument must be 'enc' or 'dec'\n");
        return 1;
    }

    // Validate that all inputs are valid positive integers
    for (int i = 2; i <= 5; i++) {
        if (!is_valid_positive_integer(argv[i])) {
            printf("Error: Negative numbers are not allowed\n");
            return 1;
        }
    }
    
    // Read arguments
    int e = atoi(argv[2]);
    int d = atoi(argv[3]);
    int p = atoi(argv[4]);
    int q = atoi(argv[5]);

    // Validate inputs
    if (p <= 0 || q <= 0 || e <= 0 || d <= 0) {
        printf("Error: All input numbers must be positive integers\n");
        return 1;
    }
    if (!is_prime(p) || !is_prime(q)) {
        printf("Error: Both p and q must be prime numbers\n");
        return 1;
    }

    long long n = p * q;
    long long phi_n = (p - 1) * (q - 1);

    if (phi_n <= 0) {
        printf("Error: phi(N) must be greater than zero\n");
        return 1;
    }
    if (gcd(e, phi_n) != 1) {
        printf("Error: e must be coprime with phi(N)\n");
        return 1;
    }
    if ((long long)e * d % phi_n != 1) {
        printf("Error: e * d mod phi(N) must be 1\n");
        return 1;
    }

    // Read the message
    long long message;
    if (scanf("%lld", &message) != 1) {
        printf("Error: Invalid input for message\n");
        return 1;
    }

    // Ensure the message is within limits
    if (message < 0 || message >= n) {
        printf("Error: Message must be in the range [0, N-1]\n");
        return 1;
    }

    // Encryption and Decryption
    if (strcmp(operation, "enc") == 0) {
        long long encrypted = mod_exp(message, e, n);
        if (encrypted == -1) {
            return 1;
        }
        printf("%lld\n", encrypted);
    } else if (strcmp(operation, "dec") == 0) {
        long long decrypted = mod_exp(message, d, n);
        if (decrypted == -1) {
            return 1;
        }
        printf("%lld\n", decrypted);
    } else {
        printf("Error: First argument must be 'enc' or 'dec'\n");
        return 1;
    }

    return 0;
}
