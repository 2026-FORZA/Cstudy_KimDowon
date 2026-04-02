#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int A, B;
	int result;

	A = 7;
	B = 3;

	result = A + B;
	printf("%d\n", result);

	result = A - B;
	printf("%d\n", result);

	result = A * B;
	printf("%d\n", result);

	result = A / B;
	printf("%d\n", result);

	result = A % B;
	printf("%d\n", result);

	return 0;
}