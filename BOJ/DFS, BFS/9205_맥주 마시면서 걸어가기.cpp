#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int vis[101];
int t;
vector<vector<int>> adj;
int dist(int a, int b, int c, int d);
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		adj.clear();
		adj.resize(n + 3);
		pair<int, int> lot[101];
		for (int i = 1; i <= n + 2; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			lot[i].first = a;
			lot[i].second = b;
		}
		for (int i = 1; i <= n + 1; i++) {
			for (int j = i; j <= n + 2; j++) {
				if (dist(lot[i].first, lot[i].second, lot[j].first, lot[j].second) <= 1000) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		vis[1] = 1;
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now][i];
				if (vis[next]) continue;
				vis[next] = 1;
				q.push(next);
			}
		}
		if (vis[n + 2]) printf("happy\n");
		else printf("sad\n");
	}
	return 0;
}
int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}