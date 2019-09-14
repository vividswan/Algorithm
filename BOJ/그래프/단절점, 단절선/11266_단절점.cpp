#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int v, e, vis[100001], res[100001], roof = 1;
int dfs(int idx, bool root);
vector<vector<int>> adj;
int main(void) {
	scanf("%d%d", &v, &e);
	adj.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!vis[i]) dfs(i, true);
	}
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (res[i]) cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= v; i++) {
		if (res[i]) printf("%d ", i);
	}
	return 0;
}
int dfs(int idx, bool root) {
	int cnt = 0;
	vis[idx] = roof;
	int ret = roof;
	roof++;
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (vis[next]) {
			ret = min(ret, vis[next]);
			continue;
		}
		int prev = dfs(next, false);
		cnt++;
		if (!root && prev >= vis[idx]) res[idx] = 1;
		ret = min(ret, prev);
	}
	if (root && cnt >= 2) res[idx] = 1;
	return ret;
}