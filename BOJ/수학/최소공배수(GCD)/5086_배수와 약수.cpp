#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	int c = max(a, b);
	int d = min(a, b);
	while (d) {
		int temp = c % d;
		c = d;
		d = temp;
	}
	return c;
}
int main(void) {
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		else if (n > m && gcd(n, m) == m) cout << "multiple" << "\n";
		else if (n < m && gcd(n, m) == n) cout << "factor" << "\n";
		else cout << "neither" << "\n";
	}
	return 0;
}