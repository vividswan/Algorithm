#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 123456789
using namespace std;
int t;
long long dist[100001];
int main() {
	scanf("%d", &t);
	while (t--) {
		fill(dist, dist + 100001, INF);
		int n, d, c;
		scanf("%d%d%d", &n, &d, &c);
		vector<vector<pair<int, int>>> adj;
		vector<int> vis;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		adj.resize(n + 1);
		vis.resize(n + 1);
		while (d--) {
			int a, b, s;
			scanf("%d%d%d", &a, &b, &s);
			adj[b].push_back({ a,s });
		}
		pq.push({ 0,c });
		dist[c] = 0;
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
		long long res = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				cnt++;
				res = max(res, dist[i]);
			}
		}
		printf("%d %lld\n", cnt, res);
	}
}