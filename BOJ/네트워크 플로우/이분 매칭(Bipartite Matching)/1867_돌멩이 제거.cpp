#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k;
int res;
int adj[510][501];
int n_adj[501];
int vis[501];
bool dfs(int idx);
int main(void) {
	scanf("%d%d", &n, &k);
	memset(n_adj, -1, sizeof(n_adj));
	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, -1, sizeof(vis));
		if (dfs(i)) res++;
	}
	printf("%d\n", res);
}
bool dfs(int idx) {
	if (vis[idx] != -1) return false;
	vis[idx] = 1;
	for (int i = 1; i <= n; i++) {
		if (adj[idx][i]) {
			if (n_adj[i] == -1 || dfs(n_adj[i])) {
				n_adj[i] = idx;
				return true;
			}
		}
	}
	return false;
}