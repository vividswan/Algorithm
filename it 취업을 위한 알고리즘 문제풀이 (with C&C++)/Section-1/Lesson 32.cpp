#include <iostream>
using namespace std;
int main(void) {
	int arr[101];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		int idx = i;
		for (int j = i + 1; j < N; j++) {
			if (arr[j] < arr[idx]) idx = j;
		}
		int tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}
	for (int i = 0; i < N; i++) cout << arr[i] << ' ';
	cout << 'endl';
}