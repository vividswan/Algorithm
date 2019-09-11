#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, indegree[32001];
vector<vector<int>> adj;
priority_queue<int, vector<int>, greater<int>>pq;
int main(void) {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) pq.push(i);
	}
	while (!pq.empty()) {
		int now = pq.top();
		printf("%d ", now);
		pq.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			indegree[next]--;
			if (!indegree[next]) pq.push(next);
		}
	}
	return 0;
}