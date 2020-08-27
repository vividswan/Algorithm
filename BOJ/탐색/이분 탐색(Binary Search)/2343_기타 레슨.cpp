#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int N, M;
	cin >> N >> M;
	vector<long long> arr(N + 1);
	long long lo = 0;
	long long hi = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		hi += arr[i];
	}
	long long result = 0;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long tot = 0;
		int cnt = 1;
		bool swc = false;
		for (int i = 1; i <= N; i++) {
			if (arr[i] > mid) break;
			if (cnt > M) break;
			if (tot + arr[i] > mid) {
				cnt++;
				tot = arr[i];
			}
			else {
				tot += arr[i];
			}
			if (cnt <= M && i == N) swc = true;
		}
		if (swc) {
			result = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << result << '\n';
	return 0;
}