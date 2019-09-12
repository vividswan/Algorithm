#include <stdio.h>
int main(void) {
	long long a, b, c;
	scanf("%lld %lld", &a, &b);
	if (a - b >= 0) c = a - b;
	else c = b - a;
	printf("%lld", c);
	return 0;
}