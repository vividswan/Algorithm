#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 10007
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<vector<long long>>dp(N + 1, vector<long long>(10));
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 9; j++) dp[i][j] = 0;
	}
	for (int i = 0; i <= 9; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;
			}
		}
	}
	int result = 0;
	for (int i = 0; i <= 9; i++) {
		result += dp[N][i];
		result %= MOD;
	}
	cout << result << '\n';
	return 0;
}