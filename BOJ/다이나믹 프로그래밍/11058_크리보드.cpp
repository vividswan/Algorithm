#include <iostream>
#include <algorithm>
using namespace std;
long long dp[101];
int n;
int main(void) {
	for (int i = 1; i <= 6; i++) {
		dp[i] = i;
	}
	scanf("%d", &n);
	if (n <= 6) {
		printf("%lld", dp[n]);
		return 0;
	}
	for (int i = 7; i <= n; i++) {
		long long a, b, c;
		a = 2 * dp[i - 3];
		b = 3 * dp[i - 4];
		c = 4 * dp[i - 5];
		dp[i] = max(a, b);
		dp[i] = max(dp[i], c);
	}
	printf("%lld\n", dp[n]);
	return 0;
}