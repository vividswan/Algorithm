#include <stdio.h>
int main(void) {
	int a, b;
	scanf("%d", &a);
	for (b = 1; b <= 8; b++) {
		printf("%d * %d = %d\n", a, b, a * b);
	}
	printf("%d * %d = %d", a, 9, a * 9);
	return 0;
}