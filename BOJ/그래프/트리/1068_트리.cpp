#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj;
void dfs(int idx);
int n, x, cnt, vis[51], root, arr[51];
queue<int> q;
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 0; i <= n - 1; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &x);
	for (int i = 0; i <= n - 1; i++) {
		if (i == x) continue;
		else if (arr[i] == x) continue;
		else if (arr[i] == -1) {
			q.push(i);
			continue;
		}
		else {
			adj[arr[i]].push_back(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (vis[now] == 0 && now != x) dfs(now);
	}
	printf("%d\n", cnt);
	return 0;
}
void dfs(int idx) {
	vis[idx] = 1;
	if (adj[idx].size() == 0) {
		cnt++;
		return;
	}
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!vis[next]) {
			dfs(next);
		}
	}
}