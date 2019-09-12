#include <stdio.h>
int main(void) {
	int a, b, c, d;
	scanf("%d", &a);
	for (b = 1; a >= b; b++) {
		for (c = 1; b >= c; c++) printf("*");
		for (d = 1; 2 * a - 2 * b >= d; d++) printf(" ");
		for (c = 1; b >= c; c++) printf("*");
		printf("\n");
	}
	for (b = a - 1; b > 0; b--) {
		for (c = 1; b >= c; c++) printf("*");
		for (d = 1; 2 * a - 2 * b >= d; d++) printf(" ");
		for (c = 1; b >= c; c++) printf("*");
		printf("\n");
	}
	return 0;
}