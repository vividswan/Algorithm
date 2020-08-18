#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100001
using namespace std;
vector<int> coinValue;
vector<int> dp;
int main(void) {
	int n, k;
	cin >> n >> k;
	dp.resize(k + 1);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		coinValue.push_back(num);
	}
	for (int i = 1; i <= k; i++) dp[i] = INF;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (coinValue[j] == i) dp[i] = 1;
			else if (coinValue[j] < i) {
				dp[i] = min(dp[i], (dp[i - coinValue[j]] + dp[coinValue[j]]));
			}
		}
	}
	if (dp[k] == INF) cout << -1 << '\n';
	else cout << dp[k] << '\n';
	return 0;
}