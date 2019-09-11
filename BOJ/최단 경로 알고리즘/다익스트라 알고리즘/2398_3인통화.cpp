#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 12345678
using namespace std;
int n, m, a, b, c, dist[1001], val[1001][1001], pre[1001][1001];
vector<vector<pair<int, int>>> adj;
void dijkstra(int st);
int main(void) {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	scanf("%d %d %d", &a, &b, &c);
	dijkstra(a);
	for (int i = 1; i <= n; i++) {
		val[a][i] = dist[i];
	}
	dijkstra(b);
	for (int i = 1; i <= n; i++) {
		val[b][i] = dist[i];
	}
	dijkstra(c);
	for (int i = 1; i <= n; i++) {
		val[c][i] = dist[i];
	}
	int res = INF;
	int go;
	for (int i = 1; i <= n; i++) {
		res = min(res, val[a][i] + val[b][i] + val[c][i]);
		if (res == val[a][i] + val[b][i] + val[c][i]) {
			go = i;
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> vis_q;
	int now = go;
	while (now != a) {
		vis_q.push({ pre[a][now],now });
		now = pre[a][now];
	}
	now = go;
	while (now != b) {
		vis_q.push({ pre[b][now],now });
		now = pre[b][now];
	}
	now = go;
	while (now != c) {
		vis_q.push({ pre[c][now],now });
		now = pre[c][now];
	}
	printf("%d %d\n", res, vis_q.size());
	while (!vis_q.empty()) {
		printf("%d %d\n", vis_q.top().first, vis_q.top().second);
		vis_q.pop();
	}
}
void dijkstra(int st) {
	fill(dist, dist + n + 1, INF);
	dist[st] = 0;
	int vis[1001] = { 0, };
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,st });
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
			int cost = adj[now][i].second;
			if (dist[next] > dist[now] + cost) {
				dist[next] = dist[now] + cost;
				pre[st][next] = now;
				pq.push({ dist[next],next });
			}
		}
	}
	return;
}