#include <stdio.h>
#include <stdlib.h>

// Calculating the GCD using the Euclidean algorithm 

long long gcd(long long a, long long b) {
    if (b == 0) {
        //Return the absolute value of a
        return llabs(a);
    }
    //Return the algorithm's results
    return gcd(b, a % b);
}

int main(int narg, char *nargt[]) {

    // Check if the number of arguments given is correct
    if (narg != 3) {
        printf("Usage: ./gcd <num1> <num2>\n");
        return 1;
    }

    // Convert arguments to (long long) integrals
    char *pntr1, *pntr2;
    long long x = strtoll(nargt[1], &pntr1, 10);
    long long y = strtoll(nargt[2], &pntr2, 10);

    // Check if arguments are of valid type
    if (*pntr1 != '\0' || *pntr2 != '\0' || x == 0 || y == 0) {
        printf("Usage: ./gcd <num1> <num2>\n");
        return 1;
    }

    // Call the gcd function to calculate the greatest common divisor
    long long result = gcd(x, y);

    // Print the results
    printf("gcd(%lld, %lld) = %lld\n", x, y, result);
    return 0;
}