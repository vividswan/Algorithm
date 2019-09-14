#include <iostream>
using namespace std;
int main(void) {
	int c, k, p;
	cin >> c >> k >> p;
	long long sum = 0;
	for (int i = 1; i <= c; i++) {
		sum += i * k + p * i * i;
	}
	cout << sum << "\n";
}