#include <stdio.h>

int main() {
    int n, i;
    long long int fib[10000];
    n = 50;

    fib[0] = 0;
    fib[1] = 1;

    // fibonacci
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // print result
    printf("fibonacci done\n");

    return 0;
}
