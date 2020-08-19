#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 2; i * (i + 1) <= 2 * N; i++) {
		int total = (i * (i + 1)) / 2;
		int now = N - total;
		if (now % i == 0) {
			cnt++;
			for (int j = 1; j <= i; j++) {
				cout << now/i + j << ' ';
				if (j != i) cout << '+' << ' ';
			}
			cout << "= " << N << '\n';
		}
	}
	cout << cnt << '\n';
	return 0;
}