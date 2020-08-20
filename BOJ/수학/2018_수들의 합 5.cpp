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
		}
	}
	cout << cnt+1 << '\n';
	return 0;
}