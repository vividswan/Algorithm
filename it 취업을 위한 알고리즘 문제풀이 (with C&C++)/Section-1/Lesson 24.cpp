#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
bool isExist[101];
bool swc = true;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i != 0) {
			isExist[abs(arr[i] - arr[i - 1])] = true;
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		if (!isExist[i]) swc = false;
	}
	if (swc) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}