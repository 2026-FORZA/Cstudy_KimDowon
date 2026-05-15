#include <stdio.h>
#include <string.h>

int main() {
    char str[1005];

    fgets(str, sizeof(str), stdin);

    int len = strlen(str);

    if (len > 0 && str[len - 1] == '\n') {
        len--;
    }

    printf("%d\n", len);

    return 0;
}