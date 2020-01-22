#include <iostream>
using namespace std;
int dp[21][21];
int main(void) {
	dp[1][1] = 1;
	for (int i = 2; i <= 20; i++) {
		for (int j = 1; j < i; j++) {
			if (j % 2) {
				if (i - j < 3) dp[i][j] += dp[i - 1][j];
			}
			else if (i - j < 4) dp[i][j] += dp[i - 1][j];
			dp[i][i] += dp[i - 1][j];
		}
	}
	int year;
	scanf("%d", &year);
	int result = 0;
	for (int i = 1; i <= year; i++) result += dp[year][i];
	printf("%d\n", result);
}