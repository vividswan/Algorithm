#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, check[30001], d[30001], par[30001][21], m, cnt;
void lca(int a, int b);
void dfs(int idx, int depth);
void go();
vector<vector<int>> adj;
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
	int pre = 0;
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		if (i == 0) {
			pre = a;
			continue;
		}
		else {
			lca(pre, a);
			pre = a;
		}
	}
	printf("%d\n", cnt);
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
void lca(int a, int b) {
	int ed;
	int first_a = a;
	int first_b = b;
	if (d[a] < d[b]) swap(a, b);
	for (int i = 20; i >= 0; i--) {
		if (d[a] - d[b] >= (1 << i)) a = par[a][i];
	}
	if (a == b) ed = b;
	else {
		for (int i = 20; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				a = par[a][i];
				b = par[b][i];
			}
			ed = par[a][0];
		}
	}
	cnt += d[first_a] + d[first_b] - (2 * d[ed]);
}