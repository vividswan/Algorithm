#include <iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int inversinArr[101];
	int resultArr[101];
	for (int i = 0; i < N; i++) cin >> inversinArr[i];
	for (int i = N - 1; i >= 0; i--) {
		int num = inversinArr[i];
		for (int j = 0; j < num; j++) {
			resultArr[i + j] = resultArr[i + j + 1];
		}
		resultArr[i + num] = i+1;
	}
	for (int i = 0; i < N; i++) cout << resultArr[i] << ' ';
	return 0;
}