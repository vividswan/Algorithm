#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int result;
int main(void) {
	int N, K;
	cin >> N >> K;
	int nowVal = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i < K) {
			result += arr[i];
			nowVal += arr[i];
		}
		else  {
			nowVal -= arr[i - K];
			nowVal += arr[i];
			result = max(result, nowVal);
		}
	}
	cout << result << '\n';
	return 0;
}