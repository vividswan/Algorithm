#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int t;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		queue<int> q;
		int n, k, w;
		int arr[1001] = { 0, };
		int indegree[1001] = { 0, };
		int cost[1001] = { 0, };
		vector<vector<int>> adj;
		scanf("%d %d", &n, &k);
		adj.resize(n + 1);
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			indegree[b]++;
		}
		scanf("%d", &w);
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
		printf("%d\n", cost[w]);
	}
}