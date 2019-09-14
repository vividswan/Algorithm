#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int vis[101];
vector<vector<int>> adj;
int main(void) {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int chk[5];
		memset(chk, 0, sizeof(chk));
		for (int j = 0; j < adj[i].size(); j++) {
			chk[vis[adj[i][j]]] = 1;
		}
		for (int k = 1; k <= 4; k++) {
			if (chk[k] == 0) {
				vis[i] = k;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", vis[i]);
	}
}