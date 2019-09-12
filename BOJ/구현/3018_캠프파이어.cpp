#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, e;
int song[101][51];
int vis[51];
int now_song;
int main(void) {
	scanf("%d%d", &n, &e);
	for (int i = 1; i <= e; i++) {
		int k;
		scanf("%d", &k);
		vector<int> adj;
		memset(vis, 0, sizeof(vis));
		for (int d = 0; d < k; d++) {
			int a;
			scanf("%d", &a);
			adj.push_back(a);
		}
		sort(adj.begin(), adj.end());
		if (adj[0] == 1) {
			now_song++;
			for (int j = 0; j < adj.size(); j++) {
				song[adj[j]][now_song] = 1;
			}
			continue;
		}
		for (int j = 0; j < adj.size(); j++) {
			int now = adj[j];
			for (int h = 1; h <= now_song; h++) {
				if (vis[h]) continue;
				if (song[now][h]) {
					vis[h] = 1;
					for (int c = 0; c < adj.size(); c++) {
						if (adj[c] == now) continue;
						song[adj[c]][h] = 1;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			printf("%d\n", i);
			continue;
		}
		int cnt = 0;
		for (int j = 1; j <= now_song; j++) {
			if (song[i][j]) cnt++;
			else break;
		}
		if (cnt == now_song) printf("%d\n", i);
	}
}