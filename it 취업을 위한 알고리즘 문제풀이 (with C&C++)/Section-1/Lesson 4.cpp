#include <iostream>
using namespace std;
int main(void) {
	int N, arr[101], result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int value = arr[i] - arr[j];
			if (value < 0) value *= -1;
			if (value > result) result = value;
		}
	}
	cout << result;
	return 0;
}