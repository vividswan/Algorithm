#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
queue<int> q;
int n, st, ed, m, arr[101], swc, pre[101], vis[101];
long long dist[101];
vector<pair<int, long long>> adj[101];
int main(void) {
	scanf("%d%d%d%d", &n, &st, &ed, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		adj[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}
	fill(dist, dist + n, INF);
	dist[st] = -arr[st];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[j] != INF) {
				for (int k = 0; k < adj[j].size(); k++) {
					int next = adj[j][k].first;
					long long d = adj[j][k].second - arr[next];
					if (dist[next] > dist[j] + d) {
						dist[next] = dist[j] + d;
						pre[next] = j;
						if (i == n - 1) {
							if (!vis[j]) {
								q.push(j);
								vis[j] = 1;
							}
						}
					}
				}
			}
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int k = 0; k < adj[now].size(); k++) {
			int next = adj[now][k].first;
			if (!vis[next]) {
				vis[next] = 1;
				q.push(next);
			}
		}
	}
	if (dist[ed] == INF) printf("gg\n");
	else if (vis[ed]) printf("Gee\n");
	else printf("%lld\n", -dist[ed]);
}