#include <iostream>
#include <algorithm>
int gcd(int a, int b);
int main(void) {
	int num1, num2, num3, num4;
	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
	int val1 = num1 * num4 + num3 * num2;
	int val2 = num2*num4;
	int temp = gcd(val1, val2);
	printf("%d %d\n", val1 / temp, val2 / temp);
	return 0;
}
int gcd(int a, int b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (b) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}