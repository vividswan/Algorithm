#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	long long result = 0;
	int N;
	cin >> N;
	vector<long long> arr;
	long long lo = 0;
	long long hi = 0;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		arr.push_back(num);
		hi = max(hi, num);
	}
	long long maxValue;
	cin >> maxValue;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long total = 0;
		for (int i = 0; i < N; i++) {
			if (mid > arr[i]) total += arr[i];
			else total += mid;
		}
		if (total <= maxValue) {
			result = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout << result << '\n';
	return 0;
}