#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 98765432
using namespace std;
bool swc;
int n, m;
int dist[201];
vector<vector<pair<int, int>>> adj;
int main(void) {
	cin >> n >> m;
	memset(dist, INF, sizeof(dist));
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		adj[st].push_back({ ed,val });
	}
	int finalSt, finalEd;
	cin >> finalSt >> finalEd;
	dist[finalSt] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < adj[j].size(); k++) {
				int next = adj[j][k].first;
				int value = adj[j][k].second;
				if (dist[j] != INF && dist[next] > dist[j] + value) {
					dist[next] = dist[j] + value;
					if (i == n - 1) {
						swc = true;
					}
				}
			}
		}
	}
	if (swc) cout << -1 << '\n';
	else cout << dist[finalEd] << '\n';
	return 0;
}