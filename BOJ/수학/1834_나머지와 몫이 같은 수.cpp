#include <stdio.h>
int main(void) {
	long long c = 0, a, b;
	scanf("%lld", &a);
	for (b = 1; a > b; b++) c = c + (b * a) + b;
	printf("%lld", c);
	return 0;
}