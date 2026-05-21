#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* str = (char*)malloc(105 * sizeof(char));
    int a, b;

    if (str == NULL) {
        return 0;
    }

    scanf("%s", str);

    scanf("%d %d", &a, &b);

    for (char* p = str + a - 1; p < str + b; p++) {
        printf("%c", *p);
    }

    free(str);

    return 0;
}