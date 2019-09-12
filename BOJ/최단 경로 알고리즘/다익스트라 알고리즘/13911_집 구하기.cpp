#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
int v, e;
int not_vis[10001];
int vis[10001];
int star[10001];
int donald[10001];
long long st_dist[10001];
long long do_dist[10001];
void st_di(int i);
void do_di(int i);
int swc = 0;
long long res = LLONG_MAX;
vector<vector<pair<int, int>>> adj;
int main(void) {
	scanf("%d %d", &v, &e);
	adj.resize(v + 3);
	for (int i = 1; i <= e; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	int st, st_limit;
	scanf("%d%d", &st, &st_limit);
	for (int i = 1; i <= st; i++) {
		scanf("%d", &star[i]);
		adj[v + 1].push_back({ star[i],0 });
		adj[star[i]].push_back({ v + 1,0 });
		not_vis[star[i]] = 1;
	}
	int don, don_limit;
	scanf("%d%d", &don, &don_limit);
	for (int i = 1; i <= don; i++) {
		scanf("%d", &donald[i]);
		adj[v + 2].push_back({ donald[i],0 });
		adj[donald[i]].push_back({ v + 2,0 });
		not_vis[donald[i]] = 1;
	}
	st_di(v + 1);
	do_di(v + 2);
	for (int i = 1; i <= v; i++) {
		if (not_vis[i]) continue;
		if (st_dist[i] > st_limit) continue;
		if (do_dist[i] > don_limit) continue;
		swc++;
		res = min(res, st_dist[i] + do_dist[i]);
	}
	if (!swc) printf("%d\n", -1);
	else printf("%lld\n", res);
}
void st_di(int i) {
	fill(st_dist, st_dist + 10001, 123456789);
	memset(vis, 0, sizeof(vis));
	st_dist[i] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,i });
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
			if (st_dist[next] > st_dist[now] + adj[now][i].second) {
				st_dist[next] = st_dist[now] + adj[now][i].second;
				pq.push({ st_dist[next],next });
			}
		}
	}
}
void do_di(int i) {
	fill(do_dist, do_dist + 10001, 123456789);
	memset(vis, 0, sizeof(vis));
	do_dist[i] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,i });
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
			if (do_dist[next] > do_dist[now] + adj[now][i].second) {
				do_dist[next] = do_dist[now] + adj[now][i].second;
				pq.push({ do_dist[next],next });
			}
		}
	}
}