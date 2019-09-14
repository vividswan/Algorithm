#include <stdio.h>
int main(void) {
	int a, b, c;
	c = 0;
	scanf("%d", &a);
	for (b = 1; a >= b; b++) c = c + b;
	printf("%d", c);
	return 0;
}