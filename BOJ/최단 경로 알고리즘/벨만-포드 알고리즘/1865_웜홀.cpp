#include <iostream>
#include <vector>
#include <algorithm>
#define INF 123456789
using namespace std;
int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m, w, dist[501], swc = 0;
		vector<pair<int, int>> adj[501];
		scanf("%d%d%d", &n, &m, &w);
		for (int i = 0; i < m; i++) {
			int s, e, t;
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back({ e,t });
			adj[e].push_back({ s,t });
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			scanf("%d%d%d", &s, &e, &t);
			adj[s].push_back({ e,-1 * t });
		}
		fill(dist, dist + n, INF);
		dist[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[j] != INF) {
					for (int k = 0; k < adj[j].size(); k++) {
						int next = adj[j][k].first;
						int d = adj[j][k].second;
						if (dist[next] > dist[j] + d) {
							dist[next] = dist[j] + d;
							if (i == n) swc++;
						}
					}
				}
			}
		}
		if (swc) printf("YES\n");
		else printf("NO\n");
	}
}