#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 최대 크기가 100이므로 넉넉하게 105 배열 선언
int matrix[105][105];

int main(void) {
    int n;
    scanf("%d", &n);

    int num = 1;
    for (int k = 0; k < 2 * n - 1; ++k) {
        if (k % 2 != 0) {
            // 홀수일 때: 우상단 방향 (↗)
            int r = (k < n - 1) ? k : n - 1;
            int c = k - r;
            while (r >= 0 && c < n) {
                matrix[r][c] = num++;
                r--;
                c++;
            }
        }
        else {
            // 짝수일 때: 좌하단 방향 (↙)
            int c = (k < n - 1) ? k : n - 1;
            int r = k - c;
            while (c >= 0 && r < n) {
                matrix[r][c] = num++;
                r++;
                c--;
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}