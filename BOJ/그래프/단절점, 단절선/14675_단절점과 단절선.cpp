#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, q, vis[100001], cut[100001], go;
int dfs(int idx, bool root);
vector<vector<int>> adj;
int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i, true);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == 1) {
			if (cut[b]) printf("yes\n");
			else printf("no\n");
		}
		else if (a == 2) {
			printf("yes\n");
		}
	}
}
int dfs(int idx, bool root) {
	int cnt = 0;
	vis[idx] = ++go;
	int ret = vis[idx];
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (vis[next]) {
			ret = min(ret, vis[next]);
			continue;
		}
		cnt++;
		int prev = dfs(next, false);
		if (!root && prev >= vis[idx]) cut[idx] = 1;
		ret = min(ret, prev);
	}
	if (root && cnt >= 2) cut[idx] = 1;
	return ret;
}