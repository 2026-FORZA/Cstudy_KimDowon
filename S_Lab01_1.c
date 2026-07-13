#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    if (scanf("%d %d", &N, &K) != 2) return 0;

    int* divisors = (int*)malloc(sizeof(int) * N);
    if (divisors == NULL) return 0;

    int count = 0;

    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            divisors[count++] = i;
        }
    }

    if (count >= K) {
        printf("%d\n", divisors[K - 1]);
    }
    else {
        printf("0\n");
    }

    free(divisors);
    return 0;
}