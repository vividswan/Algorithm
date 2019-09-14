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
	int roof;
	cin >> roof;
	for (int i = 0; i < roof; i++) {
		int cnt;
		cin >> cnt;
		long long sum = 0;
		int arr[101];
		for (int i = 0; i < cnt; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < cnt - 1; i++) {
			for (int j = i + 1; j < cnt; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << "\n";
	}
}