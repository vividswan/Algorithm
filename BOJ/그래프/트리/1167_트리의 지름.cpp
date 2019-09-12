#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int v, res, vis[100001], long_node;
vector<vector<pair<int, int>>> adj;
void dfs(int st, int cnt);
int main(void) {
	scanf("%d", &v);
	adj.resize(v + 1);
	for (int i = 1; i <= v; i++) {
		int a;
		scanf("%d", &a);
		while (1) {
			int n;
			scanf("%d", &n);
			if (n == -1) break;
			else {
				int c;
				scanf("%d", &c);
				adj[a].push_back({ n,c });
			}
		}
	}
	dfs(1, 0);
	memset(vis, 0, sizeof(vis));
	res = 0;
	dfs(long_node, 0);
	printf("%d\n", res);
}
void dfs(int st, int cnt) {
	int first_res = res;
	res = max(res, cnt);
	if (first_res != res) long_node = st;
	vis[st] = 1;
	for (int i = 0; i < adj[st].size(); i++) {
		int next = adj[st][i].first;
		int d = adj[st][i].second;
		if (!vis[next]) dfs(next, cnt + d);
	}
}