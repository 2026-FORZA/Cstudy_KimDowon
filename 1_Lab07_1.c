#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Student {
    char name[15];
    int score1;
    int score2;
    int score3;
};

int main() {
    int n;
    struct Student students[105];

    if (scanf("%d", &n) != 1) return 0;

    int top_index = 0;
    int max_score1 = -1;

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", students[i].name, &students[i].score1, &students[i].score2, &students[i].score3);

        if (students[i].score1 > max_score1) {
            max_score1 = students[i].score1;
            top_index = i; 
        }
    }

    int rank2 = 1;
    int rank3 = 1;

    for (int i = 0; i < n; i++) {
        if (students[i].score2 > students[top_index].score2) {
            rank2++;
        }
        if (students[i].score3 > students[top_index].score3) {
            rank3++;
        }
    }

    printf("%s %d %d\n", students[top_index].name, rank2, rank3);

    return 0;
}