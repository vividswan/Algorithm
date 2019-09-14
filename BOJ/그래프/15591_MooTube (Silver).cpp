#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int n, q, now;
int vis[5001];
long long arr[5001][5001];
void dfs(int i, long long cost);
vector<vector<pair<int, long long>>> adj;
int main(void) {
	scanf("%d%d", &n, &q);
	adj.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		now = i;
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		dfs(i, LLONG_MAX);
	}
	for (int i = 1; i <= q; i++) {
		int a;
		long long b;
		scanf("%lld %d", &b, &a);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (i == a) continue;
			if (arr[a][i] >= b) cnt++;
		}
		printf("%d\n", cnt);
	}
}
void dfs(int i, long long cost) {
	for (int j = 0; j < adj[i].size(); j++) {
		int next = adj[i][j].first;
		if (vis[next]) continue;
		vis[next] = 1;
		long long next_cost = adj[i][j].second;
		arr[now][next] = min(cost, next_cost);
		dfs(next, min(cost, next_cost));
	}
}