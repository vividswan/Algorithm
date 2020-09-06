#include<iostream>
#include <algorithm>
using namespace std;
int map[21][21];
bool vis[21];
int N, M;
int result;
void dfs(int idx, int value) {
	if (idx == N) {
		result = min(result, value);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (map[idx][i]) {
			if (!vis[i]) {
				vis[i] = true;
				dfs(i,value+map[idx][i]);
				vis[i] = false;
			}
		}
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		map[st][ed] = val;
		result += val;
	}
	vis[1] = true;
	dfs(1,0);
	cout << result << '\n';
	return 0;
}