#include <iostream>
#include <vector>
using namespace std;
vector<int> adj;
vector<int> fir_dfs;
vector<int> vis;
int t;
int dfs(int st, int now, int cnt);
int main(void) {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n;;
		scanf("%d", &n);
		adj.clear();
		fir_dfs.clear();
		vis.clear();
		adj.resize(n + 1);
		fir_dfs.resize(n + 1);
		vis.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &adj[i]);
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += dfs(i, i, 1);
		}
		printf("%d\n", n - res);
	}
	return 0;
}
int dfs(int st, int now, int cnt) {
	if (vis[now]) {
		if (fir_dfs[now] != st) return 0;
		return cnt - vis[now];
	}
	fir_dfs[now] = st;
	vis[now] = cnt;
	return dfs(st, adj[now], cnt + 1);
}