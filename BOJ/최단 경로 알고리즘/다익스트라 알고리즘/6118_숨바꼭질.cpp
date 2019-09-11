#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#define INF 12345678
using namespace std;
int n, m, swc, res, dist[20001];
vector<vector<pair<int, int>>> adj;
void dijkstra(int go);
int main(void) {
	scanf("%d%d", &n, &m);
	adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back({ b,1 });
		adj[b].push_back({ a,1 });
	}
	dijkstra(1);
	for (int i = 2; i <= n; i++) {
		res = max(res, dist[i]);
	}
	queue<int> q;
	for (int i = 2; i <= n; i++) {
		if (dist[i] == res) q.push(i);
	}
	printf("%d %d %d\n", q.front(), res, q.size());
}
void dijkstra(int go) {
	int vis[20001] = { 0, };
	fill(dist, dist + 20001, INF);
	dist[1] = 0;
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
			if (vis[next]) continue;
			if (dist[next] > dist[now] + adj[now][i].second) {
				dist[next] = dist[now] + adj[now][i].second;
				pq.push({ dist[next], next });
			}
		}
	}
}