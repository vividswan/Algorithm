#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define INF 12345678
using namespace std;
int n, m, dist[1001], pre[1001];
vector<vector<pair<int, int>>> adj;
vector<vector<int>> go;
int main(void) {
	cin >> n >> m;
	adj.resize(n + 1);
	go.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,1 });
	fill(dist, dist + 1001, INF);
	dist[1] = 0;
	int vis[1001] = { 0, };
	while (!pq.empty()) {
		int now;
		do {
			now = pq.top().second;
			pq.pop();
		} while (vis[now] && !pq.empty());
		if (vis[now]) continue;
		vis[now] = 1;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int cost = adj[now][i].second;
			if (vis[next]) continue;
			if (dist[next] > dist[now] + cost) {
				dist[next] = dist[now] + cost;
				pre[next] = now;
				pq.push({ dist[next],next });
			}
		}
	}
	queue<pair<int, int>> q;
	for (int i = 2; i <= n; i++) {
		int now = i;
		while (1) {
			int a = min(now, pre[now]);
			int b = max(now, pre[now]);
			int swc = 0;
			for (int i = 0; i < go[a].size(); i++) {
				if (go[a][i] == b) {
					swc++;
					break;
				}
			}
			if (!swc) go[a].push_back(b);
			if (!swc) q.push({ now,pre[now] });
			if (pre[now] == 1) break;
			now = pre[now];
		}
	}
	printf("%d\n", q.size());
	while (!q.empty()) {
		printf("%d %d\n", q.front().first, q.front().second);
		q.pop();
	}
	return 0;
}