#include <stdio.h>
int main(void) {
	int a, b, c, max, mid, min;
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) max = a;
	else max = b;
	if (c > max) max = c;
	if (a < b) min = a;
	else min = b;
	if (min > c) min = c;
	if (min < a && a < max) mid = a;
	if (min < b && b < max) mid = b;
	if (min < c && c < max) mid = c;
	printf("%d %d %d", min, mid, max);
	return 0;
}