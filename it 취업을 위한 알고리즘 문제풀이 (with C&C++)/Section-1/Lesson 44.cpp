#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int N, C;
	cin >> N >> C;
	vector<int> adj;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		adj.push_back(num);
	}
	sort(adj.begin(), adj.end());
	int leftVal = 1;
	int rightVal = adj[N - 1] - adj[0];
	int mid, result;
	while (leftVal <= rightVal) {
		mid = (leftVal + rightVal) / 2;
		int cnt = 1;
		int nowLocation = 0;
		for (int i = 1; i < N; i++) {
			if (adj[i] - adj[nowLocation] >= mid) {
				cnt++;
				nowLocation = i;
				if (cnt == C) break;
			}
		}
		if (cnt == C) {
			result = mid;
			leftVal = mid + 1;
		}
		else rightVal = mid - 1;
	}
	cout << result << '\n';
	return 0;
}