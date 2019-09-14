#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int t;
int vis[1001];
vector<vector<int>> adj;
void dfs(int idx);
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int cnt;
		int res = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &cnt);
		adj.clear();
		adj.resize(cnt + 1);
		for (int i = 1; i <= cnt; i++) {
			int a;
			scanf("%d", &a);
			adj[i].push_back(a);
		}
		for (int i = 1; i <= cnt; i++) {
			if (vis[i]) continue;
			res++;
			dfs(i);
		}
		printf("%d\n", res);
	}
}
void dfs(int idx) {
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (vis[next]) continue;
		vis[next] = 1;
		dfs(next);
	}
}