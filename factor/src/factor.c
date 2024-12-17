#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(long long num) {
  if (num < 2) {
    return 0;
  }
  if (num == 2 || num == 3) {
    return 1;
  }
  if (num % 2 == 0 || num % 3 == 0) {
    return 0;
  }
  for (long long i = 5; (i * i) <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to factorize the semiprime number
void factorize(long long semiprime) {
  long long factor1;
  long long factor2;

  // Divide the semiprime by potential factors
  for (long long i = 2; i <= sqrt(semiprime); i++) {
    if (semiprime % i == 0) {
      factor1 = i;
      factor2 = semiprime / i;
      if (is_prime(factor1) && is_prime(factor2)) {
        printf("Factors: %lld %lld\n", factor1, factor2);
        return;
      }
    }
  }

  // If no factors are found
  fprintf(stderr,
          "Error: Could not factorize the semiprime or given number is not a "
          "semiprime \n");
  exit(1);
}

int main(int argc, char *argv[]) {
  // Check for correct number of arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: ./factor <semiprime>\n");
    return 1;
  }

  // Convert the input to a long long integer
  char *endptr;
  long long semiprime = strtoll(argv[1], &endptr, 10);

  // Check if the input is a valid number
  if (*endptr != '\0' || semiprime <= 0) {
    fprintf(stderr, "Usage: ./factor <semiprime>\n");
    return 1;
  }

  // Factorize the semiprime
  factorize(semiprime);

  return 0;
}
