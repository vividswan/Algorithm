#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> adj(n);
	long long leftVal = 0;
	long long rightVal = 0;
	for (int i = 0; i < n; i++) {
		cin >> adj[i];
		rightVal = max(rightVal, adj[i]);
	}
	int result = 0;
	while (leftVal <= rightVal) {
		long long chk = 0;
		long long mid = (rightVal + leftVal) / 2;
		for (int i = 0; i < n; i++) {
			int now = adj[i] - mid;
			if (now > 0) chk += now;
		}
		if (chk >= m) {
			result = mid;
			leftVal = mid + 1;
		}
		else rightVal = mid - 1;
	}
	cout << result << '\n';
}