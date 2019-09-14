#include<stdio.h>
int main(void) {
	int num1, num2, rev1, rev2;
	scanf("%d %d", &num1, &num2);
	rev1 = num1 / 100 + ((num1 / 10) % 10) * 10 + (num1 % 10) * 100;
	rev2 = num2 / 100 + ((num2 / 10) % 10) * 10 + (num2 % 10) * 100;
	if (rev1 > rev2) printf("%d", rev1);
	else printf("%d", rev2);
	return 0;
}
