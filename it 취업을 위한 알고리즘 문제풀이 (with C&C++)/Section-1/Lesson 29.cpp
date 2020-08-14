#include <iostream>
using namespace std;
int cnt;
int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int now = i;
		while (now) {
			if (now % 10 == 3) cnt++;
			now /= 10;
		}
	}
	cout << cnt << '\n';
	return 0;
}