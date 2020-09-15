#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define INF 987654321
using namespace std;
string str;
int N, dp[1<<17], map[17][17], vis, cnt, total;
int recursion(int vis) {
	int& ret = dp[vis];
	if (ret != -1) return ret;
	if (cnt >= total) return ret = 0;
	cnt++;
	ret = INF;
	for (int i = 0; i < N; i++) {
		if (vis & (1 << i)) {
			for (int j = 0; j < N; j++) {
				if (!(vis & (1 << j))) ret = min(ret, recursion(vis | (1 << j)) + map[i][j]);
			}
		}
	}
	cnt--;
	return ret;
}
int main(void) {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'Y') {
			vis |= (1 << i);
			cnt++;
		}
	}
	cin >> total;
	int result = recursion(vis);
	if (result == INF) cout << "-1\n";
	else cout << result << '\n';
	return 0;
}