#include <iostream>
#include <vector>
#include <algorithm>
#define INF 123456789
using namespace std;
int n, m, dist[501], swc;
vector<pair<int, int>> adj[501];
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}
	fill(dist, dist + 501, INF);
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
	if (swc) printf("%d\n", -1);
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF)printf("%d\n", -1);
			else printf("%d\n", dist[i]);
		}
	}
}