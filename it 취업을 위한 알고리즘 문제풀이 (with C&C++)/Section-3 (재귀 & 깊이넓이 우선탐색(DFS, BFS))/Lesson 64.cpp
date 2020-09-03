#include <iostream>
#include <vector>
using namespace std;
int result = 0;
int N, M;
vector<vector<int>> adj;
vector<bool> vis;
void dfs(int idx) {
	if (idx == N) {
		result++;
		return;
	}
	for (int i = 0; i < adj[idx].size(); i++) {
		if (!vis[adj[idx][i]]) {
			vis[adj[idx][i]] = true;
			dfs(adj[idx][i]);
			vis[adj[idx][i]] = false;
		}
	}
}
int main(void) {
	cin >> N >> M;
	adj.resize(N + 1);
	vis.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int st, ed;
		cin >> st >> ed;
		adj[st].push_back(ed);
	}
	vis[1] = true;
	dfs(1);
	cout << result << '\n';
	return 0;
}