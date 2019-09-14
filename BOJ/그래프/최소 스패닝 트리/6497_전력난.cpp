#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int m, n;
vector<vector<pair<int, int>>>adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int vis[200000];
void prim(int idx);
int sum, res;
int main(void) {
	while (1) {
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0) break;
		sum = 0;
		res = 0;
		adj.clear();
		adj.resize(m);
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			sum += z;
			adj[x].push_back({ z,y });
			adj[y].push_back({ z,x });
		}
		prim(0);
		printf("%d\n", sum - res);
	}
	return 0;
}
void prim(int idx) {
	vis[idx] = 1;
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i].second;
		if (!vis[next]) {
			pq.push({ adj[idx][i].first,next });
		}
	}
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (!vis[p.second]) {
			res += p.first;
			prim(p.second);
			return;
		}
	}
}