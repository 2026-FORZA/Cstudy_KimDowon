#include <stdio.h>

int main(void) {
    int age;

    if (scanf("%d", &age) != 1) return 0;

    if (age >= 20) {
        printf("adult\n");
    }
    else {
        printf("%d years later\n", 20 - age);
    }

    return 0;
}