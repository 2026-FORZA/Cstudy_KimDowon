#include <stdio.h>
#include <string.h>

int main() {
    char str[10001]; // 최대 10,000자 + 널 문자
    int koi_count = 0;
    int ioi_count = 0;

    // 문자열 입력
    scanf("%s", str);

    int len = strlen(str);

    // 3글자씩 묶어서 비교하므로 i는 len - 2 전까지만 순회
    for (int i = 0; i < len - 2; i++) {
        // 'KOI' 패턴 검사
        if (str[i] == 'K' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            koi_count++;
        }
        // 'IOI' 패턴 검사
        else if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            ioi_count++;
        }
    }

    // 결과 출력
    printf("%d\n", koi_count);
    printf("%d\n", ioi_count);

    return 0;
}