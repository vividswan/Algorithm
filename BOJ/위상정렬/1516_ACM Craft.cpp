#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> q;
vector<vector<int>> adj;
int n, indegree[501], arr[501], cost[501];
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		int a;
		scanf("%d", &a);
		while (a != -1) {
			indegree[i]++;
			adj[a].push_back(i);
			scanf("%d", &a);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			cost[i] = arr[i];
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			indegree[next]--;
			cost[next] = max(cost[next], arr[next] + cost[now]);
			if (!indegree[next]) q.push(next);
		}
	}
	for (int i = 1; i <= n; i++) printf("%d\n", cost[i]);
}