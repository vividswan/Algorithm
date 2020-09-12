#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 9999999999
using namespace std;
int N;
int map[16][16];
int dp[16][1 << 16];
int recursion(int now, int vis) {
	int &ret = dp[now][vis];
	if (ret != -1) return ret;
	if (vis == (1 << N) - 1) {
		if (map[now][0] != 0) return map[now][0];
		else return INF;
	}
	ret = INF;
	for (int i = 0; i < N; i++) {
		if (vis & (1 << i) || map[now][i]==0) continue;
		ret = min(ret, recursion(i, vis | (1 << i)) + map[now][i]);
	}
	return ret;
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << recursion(0, 1) << '\n';
	return 0;
}