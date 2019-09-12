#include<stdio.h>
int main(void) {
	int a, b, c, d;
	scanf("%d", &a);
	for (b = 1; a >= b; b++) {
		for (d = (a - b); d >= 1; d--) printf(" ");
		for (c = 1; b >= c; c++) printf("*");
		printf("\n");
	}
	return 0;
}