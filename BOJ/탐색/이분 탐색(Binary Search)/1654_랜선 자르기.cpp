#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int K, N;
	cin >> K >> N;
	vector<long long> adj;
	long long lo = 1;
	long long hi = 0;
	for (int i = 0; i < K; i++) {
		long long num;
		cin >> num;
		adj.push_back(num);
		hi = max(hi, num);
	}
	long long result = 0;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		int total = 0;
		for (int i = 0; i < K; i++) {
			total += (adj[i] / mid);
		}
		if (total >= N) {
			result = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout << result << '\n';
	return 0;
}