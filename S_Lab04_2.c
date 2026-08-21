#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[35][35];

int main(void) {
    int n, m;

    // 높이 n과 종류 m 입력
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // 1. 파스칼 삼각형 미리 채우기
    map[0][0] = 1;
    for (int i = 1; i < n; i++) {
        map[i][0] = 1;

        for (int j = 1; j < i; j++) {
            map[i][j] = map[i - 1][j - 1] + map[i - 1][j];
        }

        map[i][i] = 1;
    }

    // 2. 종류(m)에 맞게 출력하기
    if (m == 1) {
        // [종류 1] 위에서 아래로
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
    else if (m == 2) {
        // [종류 2] 아래에서 위로
        for (int i = n - 1; i >= 0; i--) {
            // ★ 여기가 문제였던 곳! 공백을 정확히 1칸(" ")만 출력해야 합니다.
            for (int space = 0; space < n - 1 - i; space++) {
                printf(" ");
            }
            for (int j = 0; j <= i; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
    else if (m == 3) {
        // [종류 3] 힌트 표에 나온 규칙대로 출력
        for (int j = n - 1; j >= 0; j--) {
            for (int i = n - 1; i >= j; i--) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}