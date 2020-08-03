#include <iostream>
using namespace std;
int digit_sum(int x);
int main(void) {
	int result=0, N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		if (digit_sum(value) > digit_sum(result)) {
			result = value;
		}
		else if (digit_sum(value) == digit_sum(result)) {
			if (value > result) {
				result = value;
			}
		}
	}
	cout << result << '\n';
}
int digit_sum(int x) {
	int result = 0;
	while (x) {
		result += x % 10;
		x /= 10;
	}
	return result;
}