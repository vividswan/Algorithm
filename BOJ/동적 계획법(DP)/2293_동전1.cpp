#include <iostream>
using namespace std;
int dp[10001];
int main(void) {
	int n, k;
	int arr[101];
	dp[0] = 1;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - arr[i] >= 0) {
				dp[j] += dp[j - arr[i]];
			}
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}