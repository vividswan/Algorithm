#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int result;
vector<vector<int>>adj;
vector<bool> vis;
void dfs(int idx) {
	if (idx == N) {
		result++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (adj[idx][i]) {
			if (!vis[i]) {
				vis[i] = true;
				dfs(i);
				vis[i] = false;
			}
		}
	}
}
int main(void) {
	cin >> N >> M;
	vis.resize(N + 1);
	adj.resize(N + 1,vector<int>(N+1));
	for (int i = 0; i < M; i++) {
		int st, ed;
		cin >> st >> ed;
		adj[st][ed] = 1;
	}
	vis[1] = true;
	dfs(1);
	cout << result << '\n';
	return 0;
}