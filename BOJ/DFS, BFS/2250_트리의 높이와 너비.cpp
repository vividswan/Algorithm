#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, vis[10001], max_depth, cnt, d[10001];
int depth_min[10001], depth_max[10001];
void dfs(int idx, int depth);
void serch(int idx);
int indegree[10001];
vector<vector<int>> adj;
int main(void) {
	scanf("%d", &n);
	fill(depth_min, depth_min + 10001, 10010);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (b != -1) {
			adj[a].push_back(b);
			indegree[b]++;
		}
		else adj[a].push_back(-1);
		if (c != -1) {
			adj[a].push_back(c);
			indegree[c]++;
		}
		else adj[a].push_back(-1);
	}
	int root;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			root = i;
			break;
		}
	}
	dfs(root, 1);
	memset(vis, 0, sizeof(vis));
	serch(root);
	int res = 0;
	int res_depth;
	for (int i = 1; i <= max_depth; i++) {
		int first_res = res;
		res = max(res, depth_max[i] - depth_min[i] + 1);
		if (first_res != res) res_depth = i;
	}
	printf("%d %d\n", res_depth, res);
}
void dfs(int idx, int depth) {
	max_depth = max(max_depth, depth);
	vis[idx] = 1;
	d[idx] = depth;
	for (int i = 0; i < 2; i++) {
		int next = adj[idx][i];
		if (next == -1) continue;
		if (!vis[next]) {
			dfs(next, depth + 1);
		}
	}
}
void serch(int idx) {
	if (adj[idx].size() && adj[idx][0] != -1 && vis[adj[idx][0]] == 0) serch(adj[idx][0]);
	vis[idx] = 1;
	depth_min[d[idx]] = min(depth_min[d[idx]], cnt);
	depth_max[d[idx]] = max(depth_max[d[idx]], cnt);
	cnt++;
	if (adj[idx].size() && adj[idx][1] != -1 && vis[adj[idx][1]] == 0) serch(adj[idx][1]);
}