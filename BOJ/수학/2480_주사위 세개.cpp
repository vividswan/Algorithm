#include <stdio.h>
int main(void) {
	int a, b, c;
	int result;
	scanf("%d %d %d", &a, &b, &c);
	if (a == b && b == c) result = 10000 + a * 1000;
	else if (a == b || a == c) result = 1000 + a * 100;
	else if (b == c) result = 1000 + b * 100;
	else {
		int max;
		max = a > b ? a : b;
		max = max > c ? max : c;
		result = max * 100;
	}
	printf("%d", result);
}