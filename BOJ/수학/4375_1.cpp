#include <iostream>
using namespace std;
int main(void) {
	int n;
	while (cin >> n) {
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		int cnt = 2;
		long long val = 1;
		while (1) {
			val = ((val * 10) + 1) % n;
			if (!val) break;
			cnt += 1;
		}
		cout << cnt << "\n";
	}
	return 0;
}