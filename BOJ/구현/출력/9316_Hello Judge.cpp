#include <stdio.h>
int main(void) {
	char str[1002] = { "Hello World, Judge " };
	int roof;
	scanf("%d", &roof);
	for (int a = 1; roof >= a; a++) {
		printf("%s%d!\n", str, a);
	}
	return 0;
}