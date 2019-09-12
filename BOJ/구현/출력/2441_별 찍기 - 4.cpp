#include <stdio.h>
int main(void) {
	int a, b, c, e;
	scanf("%d", &a);
	for (b = 1; a >= b; b++) {
		for (e = 1; e <= b - 1; e++) printf(" ");
		for (c = 1; c <= a + 1 - b; c++) printf("*");
		printf("\n");
	}
	return 0;
}