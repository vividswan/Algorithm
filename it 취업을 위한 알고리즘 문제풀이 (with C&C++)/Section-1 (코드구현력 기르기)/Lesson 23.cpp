#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int main(void) {
	int N;
	cin >> N;
	int nowValue = 0;
	int cnt = 0;
	int result = 0;
	int lastValue = 100001;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (lastValue > arr[i]) {
			result = max(result, cnt);
			cnt = 1;
		}
		else {
			cnt++;
			if(i==N-1) result = max(result, cnt);
		}
		lastValue = arr[i];
	}
	cout << result << '\n';
	return 0;
}