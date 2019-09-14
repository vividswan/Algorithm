#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, k, check[100001], d[100001], par[100001][21], dist_max[100001][21], dist_min[100001][21];
int max_res, min_res;
vector<vector<pair<int, int>>>adj;
void dfs(int idx, int depth);
void go();
void lca(int a, int b);
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dfs(1, 1);
	go();
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		lca(a, b);
		printf("%d %d\n", min_res, max_res);
	}
}
void dfs(int idx, int depth) {
	check[idx] = 1;
	d[idx] = depth;
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i].first;
		if (!check[next]) {
			par[next][0] = idx;
			dist_max[next][0] = adj[idx][i].second;
			dist_min[next][0] = adj[idx][i].second;
			dfs(next, depth + 1);
		}
	}
}
void go() {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			dist_max[i][j] = max(dist_max[i][j - 1], dist_max[par[i][j - 1]][j - 1]);
			dist_min[i][j] = min(dist_min[i][j - 1], dist_min[par[i][j - 1]][j - 1]);
		}
	}
}
void lca(int a, int b) {
	int ed;
	max_res = 0;
	min_res = 987654321;
	if (d[a] < d[b]) swap(a, b);
	for (int i = 20; i >= 0; i--) {
		if (d[a] - d[b] >= (1 << i)) {
			max_res = max(dist_max[a][i], max_res);
			min_res = min(dist_min[a][i], min_res);
			a = par[a][i];
		}
	}
	if (a == b) {
		ed = a;
		return;
	}
	else {
		for (int i = 20; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				max_res = max(dist_max[a][i], max_res);
				max_res = max(dist_max[b][i], max_res);
				min_res = min(dist_min[a][i], min_res);
				min_res = min(dist_min[b][i], min_res);
				a = par[a][i];
				b = par[b][i];
			}
		}
		ed = par[a][0];
		int max_res_go = max(dist_max[a][0], dist_max[b][0]);
		int min_res_go = min(dist_min[a][0], dist_min[b][0]);
		max_res = max(max_res, max_res_go);
		min_res = min(min_res, min_res_go);
		return;
	}
}