#include <iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int value = 10;
	int cnt = 1;
	while (value < N) {
		cnt += 1;
		value *= 10;
	}
	value /= 10;
	int sum=0;
	sum += (N - value + 1) * cnt;
	while (1) {
		cnt--;
		N = value - 1;
		value /= 10;
		sum += (N - value + 1) * cnt;
		if (!value) break;
	}
	cout << sum << '\n';
	return 0;
}