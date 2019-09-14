#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v, e, vis[100001], roof;
vector<pair<int, int>> res;
int dfs(int idx, int par);
vector<vector<int>>adj;
int main(void) {
	scanf("%d%d", &v, &e);
	adj.resize(v + 1);
	for (int i = 1; i <= e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!vis[i]) dfs(i, 0);
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%d %d\n", res[i].first, res[i].second);
	}
	return 0;
}
int dfs(int idx, int par) {
	vis[idx] = ++roof;
	int ret = vis[idx];
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (next == par) continue;
		if (vis[next]) {
			ret = min(ret, vis[next]);
			continue;
		}
		int prev = dfs(next, idx);
		if (prev > vis[idx]) {
			res.push_back({ min(idx,next),max(idx,next) });
		}
		ret = min(ret, prev);
	}
	return ret;
}