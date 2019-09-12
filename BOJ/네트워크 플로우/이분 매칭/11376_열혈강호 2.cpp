#include <iostream>
#include <cstring>
using namespace std;
int vis[1001];
int n, m;
int adj[1001][1001];
int n_adj[1001];
int m_adj[1001];
int res;
bool dfs(int idx);
int main(void) {
	scanf("%d%d", &n, &m);
	memset(n_adj, -1, sizeof(n_adj));
	memset(m_adj, -1, sizeof(m_adj));
	for (int i = 1; i <= n; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 1; j <= cnt; j++) {
			int a;
			scanf("%d", &a);
			adj[i][a] = 1;
		}
	}
	for (int k = 1; k <= 2; k++) {
		for (int i = 1; i <= n; i++) {
			memset(vis, -1, sizeof(vis));
			if (dfs(i)) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
bool dfs(int idx) {
	if (vis[idx] == 1) return false;
	vis[idx]++;
	for (int i = 1; i <= m; i++) {
		if (adj[idx][i]) {
			if (m_adj[i] == -1 || dfs(m_adj[i])) {
				n_adj[idx] = i;
				m_adj[i] = idx;
				return true;
			}
		}
	}
	return false;
}