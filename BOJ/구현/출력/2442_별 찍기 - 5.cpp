#include <stdio.h>
int main(void) {
	int a, b, c, d;
	scanf("%d", &a);
	for (b = 1; a >= b; b++) {
		for (c = 1; a - b >= c; c++) printf(" ");
		for (d = 1; 2 * b - 1 >= d; d++) printf("*");
		printf("\n");
	}
	return 0;
}