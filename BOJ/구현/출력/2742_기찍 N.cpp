#include <stdio.h>
int main(void) {
	int a, b;
	scanf("%d", &a);
	for (b = a; b >= 2; b--) printf("%d\n", b);
	printf("%d", 1);
	return 0;
}