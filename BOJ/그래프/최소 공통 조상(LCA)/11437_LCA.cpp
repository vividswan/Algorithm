#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int lca(int a, int b);
vector<vector<int>> adj;
int par[50001][21], d[50001], check[50001];
void dfs(int idx, int depth);
void go();
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	go();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}
void dfs(int idx, int depth) {
	check[idx] = 1;
	d[idx] = depth;
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!check[next]) {
			par[next][0] = idx;
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
int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	for (int i = 20; i >= 0; i--) {
		if (d[a] - d[b] >= (1 << i)) a = par[a][i];
	}
	if (a == b) return a;
	for (int i = 20; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}