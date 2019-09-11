#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> adj[1005];
int n, m, u, v, visit[1005];
void bfs(int st);
int result;
int start;
int check[1005];
queue<int> q;
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		if (i == 1) {
			start = u;
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int j = 1; j <= n; j++) {
		check[j] = 1;
	}
	bfs(start);
	printf("%d", result);
}
void bfs(int st) {
	visit[st] = 1;
	q.push(st);
	while (1) {
		if (q.empty()) break;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (adj[now].size() == 0) visit[now] = 1;
			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now][i];
				if (visit[next] != 1) {
					visit[next] = 1;
					q.push(next);
				}
			}
		}
		result++;
		for (int j = 1; j <= n; j++) {
			if (check[j] == 1 && visit[j] == 0) {
				q.push(j);
				break;
			}
		}
	}
}