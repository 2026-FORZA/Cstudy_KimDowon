#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// N, M이 최대 1000이므로 넉넉하게 크기 할당 (전역 변수로 선언하여 메모리 안정성 확보)
int A[1005][1005];
int ans[1005]; // 각 식당이 최고 맛집이 되기 위한 최소 조작 횟수

int main(void) {
    int n, m;

    // N과 M 입력
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // 각 친구들의 별점 평가 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // 각 친구별로 최소 조작 횟수 계산
    for (int i = 0; i < n; i++) {
        int counts[6] = { 0 }; // 1점 ~ 5점 각각의 개수

        for (int j = 0; j < m; j++) {
            counts[A[i][j]]++;
        }

        // greater_count[v] : v점보다 '큰(초과)' 점수를 받은 식당의 개수
        int greater_count[6] = { 0 };
        greater_count[5] = 0; // 5점보다 큰 점수는 없음
        for (int v = 4; v >= 1; v--) {
            greater_count[v] = greater_count[v + 1] + counts[v + 1];
        }

        // min_cost[S] : 타겟 식당의 원래 점수가 S일 때 필요한 최소 조작 횟수
        int min_cost[6] = { 0 };
        for (int S = 1; S <= 5; S++) {
            int min_c = 999999; // 최솟값을 찾기 위해 임의의 큰 수 설정

            // 타겟 식당의 점수를 최종적으로 v (1~5) 로 맞출 때의 비용 계산
            for (int v = 1; v <= 5; v++) {
                // 1. 타겟 식당의 점수를 바꾸는 비용: 원래 점수 S와 목표 점수 v가 다르면 1회 조작
                int change_target = (S == v) ? 0 : 1;

                // 2. 다른 식당들의 점수를 낮추는 비용: v점보다 높은 점수를 받은 식당 수
                // 단, 타겟 식당 자신이 원래 v보다 큰 점수(S > v)였다면, 
                // 타겟 식당은 이미 1번에서 바꿨으므로 제외(-1) 해줍니다.
                int lower_others = greater_count[v] - ((S > v) ? 1 : 0);

                int total_cost = change_target + lower_others;

                if (total_cost < min_c) {
                    min_c = total_cost;
                }
            }
            min_cost[S] = min_c;
        }

        // 미리 계산된 최소 비용을 각 식당의 누적 정답 배열에 더하기
        for (int k = 0; k < m; k++) {
            ans[k] += min_cost[A[i][k]];
        }
    }

    // 결과 출력
    for (int k = 0; k < m; k++) {
        printf("%d ", ans[k]);
    }
    printf("\n");

    return 0;
}