#include <iostream>
#define MOD 1000000000
using namespace std;
int n;
long long res;
long long dp[101][10];
int main(void) {
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	dp[1][0] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] % MOD;
		dp[i][9] = dp[i - 1][8] % MOD;
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}
	for (int i = 1; i <= 9; i++) {
		res += dp[n][i];
	}
	printf("%d\n", res % MOD);
}