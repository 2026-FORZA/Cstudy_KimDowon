#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

char grade(int k) {
    if (k >= 90) return 'A';
    if (k >= 80) return 'B';
    if (k >= 70) return 'C';
    if (k >= 60) return 'D';
    return 'F';
}

int n;

int main() {
    scanf("%d", &n);

    printf("%c", grade(n));

    return 0;
}