#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 100001
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<int> dp(N + 1);
	for (int i = 0; i <= N; i++) dp[i] = INF;
	vector<int> value;
	for (int i = 1; i * i < N; i++) {
		value.push_back(i * i);
	}
	dp[1] = 1;
	int size = value.size();
	for (int i = 2; i <= N; i++) {
		int chk = sqrt(i);
		if (chk * chk == i) {
			dp[i] = 1;
			continue;
		}
		for (int j = 0; j < size; j++) {
			if (value[j] > i) break;
			dp[i] = min(dp[i], dp[i - value[j]] + dp[value[j]]);
		}
	}
	cout << dp[N] << '\n';
	return 0;
}