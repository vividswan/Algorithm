#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int N, M;
	cin >> N >> M;
	vector<int> adj;
	int rightVal = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		rightVal += num;
		adj.push_back(num);
	}
	int leftVal = 0;
	int mid = 0;
	int result = 0;
	while (leftVal <= rightVal) {
		mid = (leftVal + rightVal) / 2;
		int i;
		int total = 0;
		int cnt = 0;
		for (i = 0; i < N; i++) {
			if (i == 0) cnt++;
			if (mid < adj[i]) break;
			if (total + adj[i] > mid) {
				cnt++;
				if (cnt > M) break;
				total = adj[i];
			}
			else total += adj[i];
		}
		if (i == N && cnt <= M) {
			result = mid;
			rightVal = mid - 1;
		}
		else leftVal = mid + 1;
	}
	cout << result << '\n';
}