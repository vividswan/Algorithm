#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int vis[1001];
int n, m, k;
int adj[1001][1001];
int n_adj[1001];
int m_adj[1001];
int bef_res;
int res;
bool dfs1(int idx);
bool dfs2(int idx);
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
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
	for (int i = 1; i <= n; i++) {
		memset(vis, -1, sizeof(vis));
		if (dfs1(i)) res++;
	}
	bef_res = res;
	res = 0;
	memset(n_adj, -1, sizeof(n_adj));
	memset(m_adj, -1, sizeof(m_adj));
	for (int i = 1; i <= n; i++) {
		memset(vis, -1, sizeof(vis));
		if (dfs2(i)) res++;
		if (dfs2(i)) res++;
	}
	int after = res - bef_res;
	printf("%d\n", bef_res + min(k, after));
	return 0;
}
bool dfs1(int idx) {
	if (vis[idx] != -1) return false;
	vis[idx] = 1;
	for (int i = 1; i <= m; i++) {
		if (adj[idx][i]) {
			if (m_adj[i] == -1 || dfs1(m_adj[i])) {
				n_adj[idx] = i;
				m_adj[i] = idx;
				return true;
			}
		}
	}
	return false;
}
bool dfs2(int idx) {
	if (vis[idx] == 1) return false;
	vis[idx]++;
	for (int i = 1; i <= m; i++) {
		if (adj[idx][i]) {
			if (m_adj[i] == -1 || dfs2(m_adj[i])) {
				n_adj[idx] = i;
				m_adj[i] = idx;
				return true;
			}
		}
	}
	return false;
}