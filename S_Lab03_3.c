#include <stdio.h>
#include <stdbool.h>

// 10,000,000까지 담아야 하므로 스택 오버플로우 방지를 위해 전역 배열로 선언
bool isPrime[10000001];

int main() {
    int M, N;

    // M과 N 입력
    scanf("%d %d", &M, &N);

    // 1. 배열 초기화: 2부터 N까지 모두 소수(true)라고 가정
    for (int i = 2; i <= N; i++) {
        isPrime[i] = true;
    }

    // 2. 에라토스테네스의 체 알고리즘 적용
    // i * i가 N 이하일 때까지만 검사해도 충분함
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            // i의 배수들을 모두 소수가 아닌 것(false)으로 체크
            // i * i 미만의 배수들은 이미 이전 단계의 소수들에 의해 지워졌으므로 i * i부터 시작
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 3. M부터 N까지 소수의 개수 카운트
    int count = 0;
    for (int i = M; i <= N; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    // 결과 출력
    printf("%d\n", count);

    return 0;
}