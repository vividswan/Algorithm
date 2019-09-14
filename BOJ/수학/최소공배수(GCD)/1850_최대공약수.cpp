#include <iostream>
#include <cstdlib>
using namespace std;
long long n, m, a, b;
char str[30];
long long int nm_1, nm_2;
long long int gcd(long long int a, long long int b);
int main(void) {
	cin >> n >> m;
	if (n >= m) {
		a = n;
		b = m;
	}
	else {
		a = m;
		b = n;
	}
	for (int i = 1; i <= gcd(a, b); i++) {
		printf("1");
	}
}
long long int gcd(long long int a, long long int b) {
	long long int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}