#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t;
int adj[101][101];
int n_adj[101];
int m_adj[101];
int vis[101];
int res;
int n, m;
bool dfs(int idx);
int main(void) {
	scanf("%d", &t);
	while (t--) {
		memset(adj, 0, sizeof(adj));
		res = 0;
		int max_time = 0;
		int min_time = 101;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			min_time = min(min_time, a);
			max_time = max(max_time, b);
			int cnt;
			scanf("%d", &cnt);
			int hav[101];
			memset(hav, 0, sizeof(hav));
			for (int i = 1; i <= cnt; i++) scanf("%d", &hav[i]);
			for (int i = a; i < b; i++) {
				for (int j = 1; j <= cnt; j++) {
					adj[i][hav[j]] = 1;
				}
			}
		}
		res = 0;
		memset(n_adj, -1, sizeof(n_adj));
		memset(m_adj, -1, sizeof(m_adj));
		int ed = -1;
		for (int i = 0; i <= 100; i++) {
			memset(vis, -1, sizeof(vis));
			if (dfs(i)) res++;
			if (res == n) {
				ed = i + 1;
				break;
			}
		}
		printf("%d\n", ed);
	}
	return 0;
}
bool dfs(int idx) {
	if (vis[idx] != -1) return false;
	vis[idx] = 1;
	for (int i = 0; i <= 100; i++) {
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