#include <stdio.h>

int main() {
    int A, B;

    // 첫째 줄과 둘째 줄의 세 자리 자연수를 입력받음
    scanf("%d", &A);
    scanf("%d", &B);

    // (3) 1의 자리 계산
    printf("%d\n", A * (B % 10));

    // (4) 10의 자리 계산
    printf("%d\n", A * ((B / 10) % 10));

    // (5) 100의 자리 계산
    printf("%d\n", A * (B / 100));

    // (6) 최종 곱셈 결과
    printf("%d\n", A * B);

    return 0;
}