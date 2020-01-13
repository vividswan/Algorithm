#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
int dp[MAX];
int func(int val);
int main(void) {
	int N;
	scanf("%d", &N);
	fill(dp, dp + MAX, -1);
	printf("%d\n", func(N));
}
int func(int val) {
	if (val == 1) return 0;
	if (dp[val] != -1) return dp[val];
	int result = func(val - 1) + 1;
	if (val % 3 == 0) result = min(result, func(val / 3) + 1);
	if (val % 2 == 0) result = min(result, func(val / 2) + 1);
	dp[val] = result;
	return result;
}