#include <iostream>
#include <algorithm>
int map[701][701];
int dp[701][701];
using namespace std;
int main(void) {
	int H, W;
	scanf("%d%d", &H, &W);
	//vector<vector<int>> map(H + 1, vector<int>(W + 1));
	//vector<vector<int>> dp(H + 1, vector<int>(W + 1));
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] += map[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	int result = 0;
	int requestH, requestW;
	scanf("%d%d", &requestH, &requestW);
	for (int i = requestH; i <= H; i++) {
		for (int j = requestW; j <= W; j++) {
			int total = dp[i][j] - dp[i - requestH][j] - dp[i][j - requestW] + dp[i - requestH][j - requestW];
			result = max(result, total);
		}
	}
	printf("%d\n", result);
	return 0;
}