#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 12345678
using namespace std;
int n, m, vis[101], cnt, swc, dfs_max, path[101][101];
void cnt_dfs(int idx);
vector<vector<int>> adj;
queue<int> q;
priority_queue<int, vector<int>, greater<int>>pq;
int main(void) {
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			path[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		path[a][b] = 1;
		path[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (path[i][j] > path[i][k] + path[k][j]) {
					path[i][j] = path[i][k] + path[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt_dfs(i);
			int ans = INF;
			int min_swc = 0;
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				int max_swc = 0;
				for (int i = 1; i <= n; i++) {
					if (path[now][i] == INF || now == i) continue;
					max_swc = max(max_swc, path[now][i]);
				}
				ans = min(ans, max_swc);
				if (ans == max_swc) min_swc = now;
			}
			pq.push(min_swc);
		}
	}
	printf("%d\n", pq.size());
	while (!pq.empty()) {
		printf("%d\n", pq.top());
		pq.pop();
	}
}
void cnt_dfs(int idx) {
	vis[idx] = 1;
	q.push(idx);
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!vis[next]) cnt_dfs(next);
		else continue;
	}
}