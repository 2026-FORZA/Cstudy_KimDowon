#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void f(int k) {
    if (k % 2 == 0) {
        printf("even\n");
    }
    else {
        printf("odd\n");
    }
}

int main() {
    int n;

    if (scanf("%d", &n) == 1) {
        f(n);
    }

    return 0;
}