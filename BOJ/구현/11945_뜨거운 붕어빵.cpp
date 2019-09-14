#include <stdio.h>
int main(void) {
	char str[12][12];
	int a, b, i, j;
	scanf("%d %d ", &i, &j);
	for (a = 0; a < i; a++) {
		gets(str[a]);
	}
	for (a = 0; a < i; a++) {
		for (b = j - 1; b + 1; b--) {
			printf("%c", str[a][b]);
		}
		printf("\n");
	}
	return 0;
}