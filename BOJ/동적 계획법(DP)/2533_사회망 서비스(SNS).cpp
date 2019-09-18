#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> adj, go;
queue<int> q;
int n, line[1000001], vis[1000001], dp[1000001][2];
void dfs(int now);
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	go.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (line[i] == 0) {
			q.push(i);
			dp[i][0] = 0;
			dp[i][1] = 1;
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < go[now].size(); i++) {
			int next = go[now][i];
			line[next]--;
			dp[next][0] += dp[now][1];
			dp[next][1] += min(dp[now][0], dp[now][1]);
			if (!line[next]) {
				q.push(next);
				dp[next][1]++;
			}
		}
	}
	printf("%d\n", min(dp[1][1], dp[1][0]));
	return 0;
}
void dfs(int now) {
	vis[now] = 1;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (!vis[next]) {
			go[next].push_back(now);
			line[now]++;
			dfs(next);
		}
	}
}