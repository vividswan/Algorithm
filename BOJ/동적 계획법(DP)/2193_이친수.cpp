#include <iostream>
using namespace std;
long long dp[91][2];
long long recursion(int n, int val);
int main(void) {
	for (int i = 1; i <= 90; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
	dp[1][1] = 1;
	dp[1][0] = 0;
	int N;
	cin >> N;
	recursion(N, 0);
	recursion(N, 1);
	long long result = dp[N][0] + dp[N][1];
	cout << result << '\n';
	return 0;
}
long long recursion(int n, int val) {
	if (dp[n][val] != -1) return dp[n][val];
	if (val == 0) {
		return dp[n][0] = (recursion(n - 1, 1) + recursion(n - 1, 0));
	}
	else {
		return dp[n][1] = recursion(n - 1, 0);
	}
}