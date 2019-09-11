#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#define INF 12345678
using namespace std;
int n, m, st, ed;
int dist[501];
vector<vector<pair<int, int>>> adj;
vector<vector<int>> line;
void dijkstra(int go, int ed);
void bfs(int a);
int main(void) {
	while (1) {
		int go_min[501] = { 0, };
		stack<int> s;
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		adj.clear();
		line.clear();
		adj.resize(n + 1);
		line.resize(n + 1);
		scanf("%d %d", &st, &ed);
		for (int i = 1; i <= m; i++) {
			int u, v, p;
			scanf("%d%d%d", &u, &v, &p);
			adj[u].push_back({ v,p });
			line[v].push_back(u);
		}
		dijkstra(st, ed);
		bfs(ed);
		dijkstra(st, ed);
		if (dist[ed] >= INF) printf("-1\n");
		else printf("%d\n", dist[ed]);
	}
	return 0;
}
void dijkstra(int go, int ed) {
	int vis[501] = { 0, };
	fill(dist, dist + n + 1, INF);
	dist[go] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,go });
	while (!pq.empty()) {
		int now;
		do {
			now = pq.top().second;
			pq.pop();
		} while (!pq.empty() && vis[now]);
		if (vis[now]) continue;
		vis[now] = 1;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			if (adj[now][i].second == -1) continue;
			if (vis[next]) continue;
			if (dist[next] > dist[now] + adj[now][i].second) {
				dist[next] = dist[now] + adj[now][i].second;
				pq.push({ dist[next], next });
			}
		}
	}
}
void bfs(int a) {
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < line[now].size(); i++) {
			int next = line[now][i];
			for (int j = 0; j < adj[next].size(); j++) {
				if (adj[next][j].first == now) {
					if (dist[now] == dist[next] + adj[next][j].second) {
						adj[next][j].second = -1;
						q.push(next);
					}
				}
			}
		}
	}
}