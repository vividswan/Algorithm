#include <iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int arr[101];
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++) cout << arr[i] << ' ';
	return 0;
}