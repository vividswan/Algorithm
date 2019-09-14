#include <iostream>
using namespace std;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long dp[65][11];
		long long res = 0;
		int n;
		scanf("%d", &n);
		if (n == 1) {
			printf("10\n");
			continue;
		}
		for (int i = 1; i <= 10; i++) {
			dp[1][i] = i;
		}
		for (int i = 2; i < n; i++) {
			dp[i][1] = 1;
			for (int j = 2; j <= 10; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		for (int i = 1; i <= 10; i++) {
			res += dp[n - 1][i];
		}
		printf("%lld\n", res);
	}
	return 0;
}