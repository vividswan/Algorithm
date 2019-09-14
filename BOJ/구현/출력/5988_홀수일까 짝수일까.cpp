#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
	char str[105];
	int num;
	scanf("%d ", &num);
	for (int a = 0; num > a; a++) {
		scanf("%s", str);
		int b = atoi(&str[strlen(str) - 1]);
		if (b % 2 == 1) printf("odd\n");
		else if (b % 2 == 0) printf("even\n");
	}
	return 0;
}