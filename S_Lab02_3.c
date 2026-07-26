#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int K;
    if (scanf("%d", &K) != 1) return 0;

    int dir[6];
    int len[6];

    int max_w = 0, max_w_idx = 0; // 가장 긴 가로 (1:동, 2:서)
    int max_h = 0, max_h_idx = 0; // 가장 긴 세로 (3:남, 4:북)

    for (int i = 0; i < 6; i++) {
        scanf("%d %d", &dir[i], &len[i]);

        // 동(1) 또는 서(2)인 경우
        if (dir[i] == 1 || dir[i] == 2) {
            if (len[i] > max_w) {
                max_w = len[i];
                max_w_idx = i;
            }
        }
        // 남(3) 또는 북(4)인 경우
        else {
            if (len[i] > max_h) {
                max_h = len[i];
                max_h_idx = i;
            }
        }
    }

    // 배열의 원형 순회를 고려한 인덱스 계산 ((idx + 5) % 6 은 이전, (idx + 1) % 6 은 다음)
    int sub_h = abs(len[(max_w_idx + 5) % 6] - len[(max_w_idx + 1) % 6]);
    int sub_w = abs(len[(max_h_idx + 5) % 6] - len[(max_h_idx + 1) % 6]);

    // 면적 계산
    int total_area = max_w * max_h;
    int sub_area = sub_w * sub_h;
    int field_area = total_area - sub_area;

    // 참외 수 출력
    printf("%d\n", field_area * K);

    return 0;
}