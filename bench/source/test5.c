#include <stdio.h>

#define N 100

void matmul(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N];
    int B[N][N];
    int C[N][N];

    //Initiallize
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }

    // matrix multiply
    matmul(A, B, C);

    // print result
    printf("matmul done\n");

    return 0;
}
