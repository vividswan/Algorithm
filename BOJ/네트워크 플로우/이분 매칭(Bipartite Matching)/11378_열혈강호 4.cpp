#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int vis[1001];
int n, m, k;
int adj[1001][1001];
int n_adj[1001];
int m_adj[1001];
int res;
int swc;
int pre_res;
int prev_num;
bool dfs(int idx);
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
	while (1) {
		for (int i = 1; i <= n; i++) {
			memset(vis, -1, sizeof(vis));
			if (dfs(i)) res++;
		}
		if (swc == 0) {
			swc = 1;
			pre_res = res;
		}
		if (prev_num == res) break;
		prev_num = res;
	}
	printf("%d\n", pre_res + min(k, res - pre_res));
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