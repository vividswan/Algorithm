#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int arr[50001];
int sum[50001];
int dp[4][50001];
int ans;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum[i] = arr[i] + sum[i - 1];
	}
	scanf("%d", &k);
	for (int i = 1; i <= 3; i++) {
		for (int j = i * k; j <= n; j++) {
			if (i == 1) {
				dp[i][j] = max(dp[i][j - 1], sum[j] - sum[j - k]);
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + sum[j] - sum[j - k]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}