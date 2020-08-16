#include <iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int arr[101];
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < N; i++) {
		int tmp = arr[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (tmp < arr[j]) arr[j + 1] = arr[j];
			else break;
		}
		arr[j + 1] = tmp;
	}
	for (int i = 0; i < N; i++) cout << arr[i] << ' ';
	return 0;
}