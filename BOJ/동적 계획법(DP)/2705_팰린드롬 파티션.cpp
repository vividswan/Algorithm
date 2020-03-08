#include <iostream>
using namespace std;
int T, dp[1001];
int main(void) {
	for (int i = 1; i <= 1001; i++) dp[i] = 1;
	for (int i = 1; i <= 1001; i++) {
		for (int j = 0; j <= i; j++) {
			if (!((i - j) % 2)) {
				dp[i] += dp[(i - j) / 2];
			}
		}
	}
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
	return 0;
}