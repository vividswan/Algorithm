#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int res;
int vis[201];
int adj[201][201];
int a_adj[201];
int b_adj[201];
bool dfs(int idx);
int main(void) {
	memset(a_adj, -1, sizeof(a_adj));
	memset(b_adj, -1, sizeof(b_adj));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		for (int j = 1; j <= a; j++) {
			int b;
			scanf("%d", &b);
			adj[i][b] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) res++;
	}
	printf("%d\n", res);
}
bool dfs(int idx) {
	if (vis[idx]) return false;
	vis[idx] = 1;
	for (int i = 1; i <= m; i++) {
		if (adj[idx][i]) {
			if (b_adj[i] == -1 || dfs(b_adj[i])) {
				a_adj[idx] = i;
				b_adj[i] = idx;
				return true;
			}
		}
	}
	return false;
}