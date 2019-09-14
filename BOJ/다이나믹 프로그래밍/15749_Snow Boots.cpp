#include <iostream>
using namespace std;
int n, b;
int dp[251][251];
void go(int idx, int foot);
int vis[251][251];
int high[251], foothigh[251], footdist[251];
int main(void) {
	scanf("%d %d", &n, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &high[i]);
	}
	for (int i = 1; i <= b; i++) {
		scanf("%d %d", &foothigh[i], &footdist[i]);
	}
	go(1, 1);
	for (int i = 1; i <= b; i++) {
		if (dp[n][i]) {
			printf("%d\n", i - 1);
			return 0;
		}
	}
}
void go(int idx, int foot) {
	dp[idx][foot] = 1;
	if (idx == n) return;
	for (int i = foot; i <= b; i++) {
		if (foothigh[i] < high[idx]) continue;
		for (int j = idx + 1; j <= idx + footdist[i]; j++) {
			if (j > n) break;
			if (high[j] <= foothigh[i]) {
				if (dp[j][i] == 0)	go(j, i);
			}
			continue;
		}
	}
}