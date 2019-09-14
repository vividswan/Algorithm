#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> adj[100010];
int indegree[100010];
int in_scc[100010];
int dfsn[100010];
int fin[100010];
stack<int> s;
int t, n, m, cnt, scc_num;
int dfs(int idx);
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dfsn, 0, sizeof(dfsn));
		memset(fin, 0, sizeof(fin));
		memset(in_scc, 0, sizeof(in_scc));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 0; i < 100010; i++) adj[i].clear();
		scc_num = 0;
		cnt = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfsn[i]) dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				int next = adj[i][j];
				if (in_scc[i] != in_scc[next]) {
					indegree[in_scc[next]]++;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < scc_num; i++) {
			if (indegree[i] == 0) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
int dfs(int idx) {
	dfsn[idx] = ++cnt;
	int result = dfsn[idx];
	s.push(idx);
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!dfsn[next]) result = min(result, dfs(next));
		else if (!fin[next]) result = min(result, dfsn[next]);
	}
	if (result == dfsn[idx]) {
		while (1) {
			int now = s.top();
			s.pop();
			fin[now] = 1;
			in_scc[now] = scc_num;
			if (now == idx) break;
		}
		scc_num++;
	}
	return result;
}