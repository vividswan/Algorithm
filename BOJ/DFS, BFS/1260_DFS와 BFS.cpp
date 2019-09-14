#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int n, m, x;
int dist[20001], vis[20001];
vector<vector<pair<int, int>>> adj;
int dijkstra(int a, int b);
int main(void) {
	scanf("%d %d %d", &n, &m, &x);
	adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v,w });
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dijkstra(i, x) + dijkstra(x, i));
	}
	printf("%d\n", res);
}
int dijkstra(int a, int b) {
	fill(dist, dist + n + 1, 123456789);
	memset(vis, 0, sizeof(vis));
	dist[a] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,a });
	while (!pq.empty()) {
		int now;
		do {
			now = pq.top().second;
			pq.pop();
		} while (!pq.empty() && vis[now]);
		if (vis[now]) break;
		vis[now] = 1;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			if (vis[next]) continue;
			if (dist[next] > dist[now] + adj[now][i].second) {
				dist[next] = dist[now] + adj[now][i].second;
				pq.push({ dist[next],next });
			}
		}
	}
	return dist[b];
}