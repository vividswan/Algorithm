#include<stdio.h>
int main(void) {
	int a, b, c;
	int num = 0;
	scanf("%d %d", &a, &b);
	for (c = 1; a >= c; c++) {
		if (a % c == 0) num++;
		if (num == b) break;
	}
	if (num == b) printf("%d", c);
	else printf("0");
	return 0;
}