#include <iostream>
#include <algorithm>
using namespace std;
int T, n;
const int TOTAL = 100001;
int dp[TOTAL][3];
int stickerVal[2][TOTAL];
int result(int nowCol, int usedPos);
int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &stickerVal[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = -1;
			}
		}
		printf("%d\n", result(0,0));
	}
}
int result(int nowCol, int usedPos) {
	if (nowCol == n) return 0;
	if (dp[nowCol][usedPos] != -1) return dp[nowCol][usedPos];
	dp[nowCol][usedPos] = result(nowCol + 1, 0);
	if (usedPos != 1) dp[nowCol][usedPos] = max(dp[nowCol][usedPos], result(nowCol+1,1)+stickerVal[0][nowCol]);
	if (usedPos != 2) dp[nowCol][usedPos] = max(dp[nowCol][usedPos], result(nowCol + 1, 2) + stickerVal[1][nowCol]);
	return dp[nowCol][usedPos];
}