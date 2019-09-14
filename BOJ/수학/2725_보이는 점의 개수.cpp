#include <iostream>
using namespace std;
int res[1001] = { 0,2 };
int gcd(int a, int b) {
	while (a % b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return b;
}
int main(void) {
	res[1] = 2;
	for (int i = 2; i <= 1000; i++) {
		int pl = 0;
		for (int j = 1; j <= i; j++) {
			if (gcd(i, j) == 1) pl++;
		}
		res[i] = res[i - 1] + pl;
	}
	int c;
	scanf("%d", &c);
	for (int i = 1; i <= c; i++) {
		int n;
		scanf("%d", &n);
		printf("%d\n", res[n] * 2 - 1);
	}
}