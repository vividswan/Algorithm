#include <stdio.h>
int main(void) {
	int a, b, c, max, min;
	scanf("%d", &a);
	scanf("%d", &b);
	max = b;
	min = b;
	for (c = 1; a > c; c++) {
		scanf("%d", &b);
		if (max < b) max = b;
		if (min > b) min = b;
	}
	printf("%d", max - min);
	return 0;
}