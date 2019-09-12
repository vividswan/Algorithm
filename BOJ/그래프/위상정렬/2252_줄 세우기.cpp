#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n, m, indegree[32001];
vector<int> adj[32001];
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			indegree[next]--;
			if (!indegree[next]) q.push(next);
		}
	}
	return 0;
}