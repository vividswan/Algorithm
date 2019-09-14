#include <stdio.h>
int gcd(int a, int b);
int main() {
	int num1, num2, num3;
	scanf("%d %d", &num1, &num2);
	if (num1 >= num2) num3 = gcd(num1, num2);
	else num3 = gcd(num2, num1);
	printf("%d\n%d", num3, num3 * (num1 / num3) * (num2 / num3));
	return 0;
}
int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
