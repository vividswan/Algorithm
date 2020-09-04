#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int result;
vector<vector<pair<int,int>>>adj;
vector<bool> vis;
void dfs(int idx, int value) {
	if (idx == N) {
		result = min(result, value);
		return;
	}
	for (int i = 0; i < adj[idx].size(); i++) {
		if (!vis[adj[idx][i].first]) {
			vis[adj[idx][i].first] = true;
			dfs(adj[idx][i].first, value + adj[idx][i].second);
			vis[adj[idx][i].first] = false;
		}
	}
}
int main(void) {
	cin >> N >> M;
	adj.resize(N + 1);
	vis.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		adj[st].push_back({ ed,val });
		result += val;
	}
	vis[1] = true;
	dfs(1 , 0);
	cout << result << '\n';
	return 0;
}