#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	while (b) {
		int temp;
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int a = max(n, m);
	int b = min(n, m);
	printf("%d\n", m - gcd(a, b));
	return 0;
}