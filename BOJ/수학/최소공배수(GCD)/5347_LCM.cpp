#include <stdio.h>
int gcd(int a, int b);
int main() {
	int roof, i;
	scanf("%d", &roof);
	for (i = 1; i <= roof; i++) {
		int num1, num2, num3;
		scanf("%d %d", &num1, &num2);
		if (num1 >= num2) {
			num3 = gcd(num1, num2);
		}
		else num3 = gcd(num2, num1);
		printf("%d\n", num3 * (num1 / num3) * (num2 / num3));
	}
	return 0;
}
int gcd(int a, int b) {
	int c;
	while (b) {
		c = a;
		a = b;
		b = c % a;
	}
	return a;
}