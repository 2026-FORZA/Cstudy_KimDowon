#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // 입력 범위를 벗어나면 INPUT ERROR! 출력
    if (n < 1 || n > 100 || m < 1 || m > 3) {
        printf("INPUT ERROR!\n");
        return 0;
    }

    // 종류에 따른 별 출력
    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (m == 2) {
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (m == 3) {
        for (int i = 1; i <= n; i++) {
            // 공백 출력
            for (int j = 1; j <= n - i; j++) {
                printf(" ");
            }
            // 별 출력 (2 * i - 1 개)
            for (int j = 1; j <= 2 * i - 1; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
