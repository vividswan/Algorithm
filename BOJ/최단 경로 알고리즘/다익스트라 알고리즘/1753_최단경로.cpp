#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int v, e, k;
int dist[20001], vis[20001];
vector<vector<pair<int, int>>> adj;
int main(void) {
	scanf("%d %d %d", &v, &e, &k);
	fill(dist, dist + 20001, 123456789);
	dist[k] = 0;
	adj.resize(v + 1);
	for (int i = 1; i <= e; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v,w });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,k });
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
	for (int i = 1; i <= v; i++) {
		if (dist[i] == 123456789) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}