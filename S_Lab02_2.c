#include <stdio.h>

int main(void) {
    long long n;

    if (scanf("%lld", &n) != 1) return 0;

    // (N + 1) * (N + 2) / 2
    long long ans = (n + 1) * (n + 2) / 2;

    printf("%lld\n", ans);

    return 0;
}