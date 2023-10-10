#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool isPrime(unsigned long long int n) {
    if (n <= 1) return false; 

    if (n % 2 == 0) return false;

    for (unsigned long long int i = 2; i < n; i ++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    unsigned long long int maxNumber = 1000000; 

    for (unsigned long long int i = maxNumber; i >= 2; i--) {
        if (isPrime(i)) {
            printf("Largest prime %llu\n", i);
            break;
        }
    }

    return 0;
}
