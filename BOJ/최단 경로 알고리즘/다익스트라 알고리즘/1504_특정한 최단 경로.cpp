#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#define INF 12345678
using namespace std;
int n, e, swc;
vector<vector<pair<int, int>>> adj;
int dijkstra(int go, int ed);
int main(void) {
	scanf("%d%d", &n, &e);
	adj.resize(n + 1);
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	int a, b;
	scanf("%d%d", &a, &b);
	int res_1 = dijkstra(1, a) + dijkstra(a, b) + dijkstra(b, n);
	int res_2 = dijkstra(1, b) + dijkstra(b, a) + dijkstra(a, n);
	if (res_1 >= INF || res_2 > +INF) printf("-1\n");
	else printf("%d\n", min(res_1, res_2));
}
int dijkstra(int go, int ed) {
	int dist[801], vis[801] = { 0, };
	fill(dist, dist + 801, INF);
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
			if (vis[next]) continue;
			if (dist[next] > dist[now] + adj[now][i].second) {
				dist[next] = dist[now] + adj[now][i].second;
				pq.push({ dist[next], next });
			}
		}
	}
	return dist[ed];
}