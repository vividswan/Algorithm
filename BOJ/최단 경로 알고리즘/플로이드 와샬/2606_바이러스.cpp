#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
int n, m, res, vis[101];
void dfs(int a);
int main(void) {
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		if (vis[i]) res++;
	}
	cout << res << "\n";
	return 0;
}
void dfs(int a) {
	vis[a] = 1;
	for (int i = 0; i < adj[a].size(); i++) {
		int next = adj[a][i];
		if (vis[next]) continue;
		else dfs(next);
	}
}