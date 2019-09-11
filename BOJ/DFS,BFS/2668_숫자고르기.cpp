#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, vis[101], chk[101], res;
vector<int> adj;
int bfs(int i);
void check(int i);
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &adj[i]);
	}
	for (int i = 1; i <= n; i++) {
		int a = bfs(i);
		memset(vis, 0, sizeof(vis));
		if (a) {
			check(i);
			memset(vis, 0, sizeof(vis));
		}
	}
	printf("%d\n", res);
	for (int i = 1; i <= n; i++) {
		if (chk[i]) printf("%d\n", i);
	}
	return 0;
}
int bfs(int i) {
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == i && vis[now]) return 1;
		if (chk[now]) return 0;
		int next = adj[now];
		if (!vis[next]) {
			vis[next] = 1;
			q.push(next);
		}
	}
	return 0;
}
void check(int i) {
	if (vis[i]) return;
	res++;
	chk[i] = 1;
	vis[i] = 1;
	int next = adj[i];
	if (!vis[next]) check(next);
}