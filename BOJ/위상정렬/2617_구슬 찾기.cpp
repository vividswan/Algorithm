#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int than_big[100], than_small[100], vis[100];
vector<vector<int>> adj;
queue<int> q;
int main(void) {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	int mid = (n + 1) / 2;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		q.push(i);
		than_small[i]--;
		while (!q.empty()) {
			int now = q.front();
			than_small[i]++;
			q.pop();
			for (int j = 0; j < adj[now].size(); j++) {
				int next = adj[now][j];
				if (!vis[next]) {
					than_big[next]++;
					vis[next]++;
					q.push(next);
				}
			}
		}
		memset(vis, 0, sizeof(vis));
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (than_big[i] >= mid || than_small[i] >= mid) res++;
	}
	printf("%d\n", res);
}