#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int adj[101][101];
int per_adj[101];
int note_adj[101];
int vis[101];
int res;
bool dfs(int idx);
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a][b] = 1;
	}
	memset(per_adj, -1, sizeof(per_adj));
	memset(note_adj, -1, sizeof(note_adj));
	for (int i = 1; i <= n; i++) {
		memset(vis, -1, sizeof(vis));
		if (dfs(i)) res++;
	}
	printf("%d\n", res);
	return 0;
}
bool dfs(int idx) {
	if (vis[idx] != -1) return false;
	vis[idx] = 1;
	for (int i = 1; i <= n; i++) {
		if (adj[idx][i]) {
			if (note_adj[i] == -1 || dfs(note_adj[i])) {
				per_adj[idx] = i;
				note_adj[i] = idx;
				return true;
			}
		}
	}
	return false;
}