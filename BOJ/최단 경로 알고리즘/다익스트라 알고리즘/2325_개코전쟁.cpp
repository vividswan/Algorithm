#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, ll> p;
typedef pair<ll, int> qp;
void da(int st, int ed);
vector<vector<p>> adj;
int n, m, pre[1001];
ll res;
int main(void) {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		ll z;
		scanf("%d %d %lld", &x, &y, &z);
		adj[x].push_back({ y,z });
		adj[y].push_back({ x,z });
	}
	da(0, 0);
	stack<pair<int, int>>s;
	int now = n;
	int back = pre[now];
	s.push({ back,now });
	while (back != 1) {
		now = pre[now];
		back = pre[now];
		s.push({ back,now });
	}
	while (!s.empty()) {
		auto a = s.top();
		s.pop();
		da(a.first, a.second);
	}
	printf("%lld\n", res);
}
void da(int st, int ed) {
	ll dist[1001];
	int vis[1001];
	fill(dist, dist + n + 1, LLONG_MAX);
	fill(vis, vis + n + 1, 0);
	dist[1] = 0;
	priority_queue < qp, vector<qp>, greater<qp>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int now;
		do {
			now = pq.top().second;
			pq.pop();
		} while (!pq.empty() && vis[now]);
		if (vis[now]) break;
		vis[now] = 1;
		for (int i = 0; i < adj[now].size(); i++) {
			auto p = adj[now][i];
			int next = p.first;
			ll d = p.second;
			if (now == st && next == ed) continue;
			if (now == ed && next == st) continue;
			if (dist[next] > dist[now] + d) {
				dist[next] = dist[now] + d;
				pq.push({ dist[next],next });
				pre[next] = now;
			}
		}
	}
	if (dist[n] != LLONG_MAX) res = max(res, dist[n]);
}