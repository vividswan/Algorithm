#include <stdio.h>
int main(void) {
	int a, b;
	scanf("%d", &a);
	for (b = 1; a > b; b++) printf("%d\n", b);
	printf("%d", a);
	return 0;
}