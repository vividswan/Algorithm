#include <iostream>
using namespace std;
int main(void) {
	int n;
	scanf("%d", &n);
		if (n == 1) {
			cout << 1 << "\n";
			return 0;
		}
		if (n % 2 == 0 || n % 5 == 0) {
			cout << -1 << "\n";
			return 0;
		}
		int cnt = 2;
		long long val = 1;
		while (1) {
			val = ((val * 10) + 1) % n;
			if (!val) break;
			cnt += 1;
		}
		cout << cnt << "\n";
	return 0;
}