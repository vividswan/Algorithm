#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> vis;
vector<vector<int>> adj;
vector<int> val;
int main(void) {
	int n,m;
	cin >> n >> m;
	vis.resize(n + 1);
	for (int i = 1; i <= n; i++) vis[i] = -1;
	adj.resize(n + 1);
	val.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int st, ed;
		cin >> st >> ed;
		adj[st].push_back(ed);
	}
	queue<int> q;
	q.push(1);
	vis[1] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			if (vis[adj[now][i]] == -1) {
				vis[adj[now][i]] = vis[now] + 1;
				q.push(adj[now][i]);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << i << " : " << vis[i] << '\n';
	}
	return 0;
}