#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 10007
using namespace std;
int main(void) {
	int n;
	cin >> n;
	vector<long long> dp;
	dp.resize(n+1);
	dp[1] = 1;
	if (n >= 2) dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]*2)%MOD;
	}
	cout << dp[n] << '\n';
	return 0;
}