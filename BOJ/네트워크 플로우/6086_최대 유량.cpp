#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 98765432
using namespace std;
int c[55][55];
int f[55][55];
int vis[55];
vector<int> adj[55];
int n;
queue<int> q;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char a, b;
		int val_a;
		int val_b;
		int val;
		scanf(" %c %c %d", &a, &b, &val);
		if ('A' <= a && a <= 'Z') val_a = a - 'A';
		else val_a = a - 'a' + 26;
		if ('A' <= b && b <= 'Z') val_b = b - 'A';
		else val_b = b - 'a' + 26;
		adj[val_a].push_back(val_b);
		adj[val_b].push_back(val_a);
		c[val_a][val_b] += val;
		c[val_b][val_a] += val;
	}
	int res = 0;
	int s = 0;
	int t = 'Z' - 'A';
	while (1) {
		memset(vis, -1, sizeof(vis));
		q.push(s);
		while (!q.empty()) {
			auto now = q.front();
			q.pop();
			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now][i];
				if (vis[next] != -1) continue;
				if (c[now][next] - f[now][next] > 0) {
					q.push(next);
					vis[next] = now;
					if (next == t) break;
				}
			}
		}
		if (vis[t] == -1) break;
		int flow = INF;
		for (int i = t; i != s; i = vis[i]) {
			flow = min(flow, c[vis[i]][i] - f[vis[i]][i]);
		}
		for (int i = t; i != s; i = vis[i]) {
			f[vis[i]][i] += flow;
			f[i][vis[i]] -= flow;
		}
		res += flow;
	}
	printf("%d\n", res);
	return 0;
}