#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, d[40001], check[40001], par[40001][21], ed;
long long val[40001];
vector<vector<pair<int, long long>>> adj;
long long lca(int a, int b);
void dfs(int idx, int depth);
void go();
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dfs(1, 1);
	go();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", lca(a, b));
	}
	return 0;
}
void dfs(int idx, int depth) {
	check[idx] = 1;
	d[idx] = depth;
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i].first;
		if (!check[next]) {
			par[next][0] = idx;
			val[next] = val[idx] + adj[idx][i].second;
			dfs(next, depth + 1);
		}
	}
}
void go() {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}
long long lca(int a, int b) {
	int first_a = a;
	int first_b = b;
	if (d[a] < d[b]) swap(a, b);
	for (int i = 20; i >= 0; i--) {
		if (d[a] - d[b] >= (1 << i)) a = par[a][i];
	}
	if (a == b) ed = a;
	else {
		for (int i = 20; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				a = par[a][i];
				b = par[b][i];
			}
		}
		ed = par[a][0];
	}
	long long dist = 0;
	dist += val[first_a] - val[ed];
	dist += val[first_b] - val[ed];
	return dist;
}