#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int n;
int dp[MAX][4];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (i == 1) {
			dp[1][1] = a;
			dp[1][2] = b;
			dp[1][3] = c;
		}
		else {
			dp[i][1] = min(dp[i - 1][2] + a, dp[i - 1][3] + a);
			dp[i][2] = min(dp[i - 1][1] + b, dp[i - 1][3] + b);
			dp[i][3] = min(dp[i - 1][1] + c, dp[i - 1][2] + c);
		}
	}
	int res = dp[n][1];
	for (int i = 2; i <= 3; i++) res = min(res, dp[n][i]);
	printf("%d\n", res);
	return 0;
}