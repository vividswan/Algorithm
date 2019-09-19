#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100001;
vector<vector<int>> adj;
bool finished[MAX];
stack<int> s;
int dfsn[MAX];
int dfs(int curr);
int n, m, st, t, st_scc, t_scc;
int scc_num[MAX];
int cnt;
int scc_cnt;
int scc_size[MAX];
int indegree[MAX];
int able[MAX];
int cost[MAX];
vector<vector<int>> scc_adj;
int main(void) {
	scanf("%d%d%d%d", &n, &m, &st, &t);
	adj.resize(n + 1);
	scc_adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		adj[from].push_back(to);
	}
	for (int i = 1; i <= n; i++) if (!dfsn[i]) dfs(i);
	for (int i = 1; i <= n; i++) {
		for (int next : adj[i]) {
			if (scc_num[i] != scc_num[next]) {
				indegree[scc_num[next]]++;
				scc_adj[scc_num[i]].push_back(scc_num[next]);
			}
		}
	}
	queue<int> q;
	able[st_scc] = 1;
	for (int i = 1; i <= scc_cnt; i++) {
		cost[i] = scc_size[i];
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : scc_adj[now]) {
			if (able[now]) {
				cost[next] = max(cost[next], cost[now] + scc_size[next]);
				able[next] = 1;
			}
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
	if (able[t_scc] == 0) printf("%d\n", 0);
	else printf("%d\n", cost[t_scc]);
	return 0;
}
int dfs(int curr) {
	dfsn[curr] = ++cnt;
	int result = dfsn[curr];
	s.push(curr);

	for (int next : adj[curr]) {
		if (!dfsn[next]) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	if (result == dfsn[curr]) {
		vector<int> now_scc;
		scc_cnt++;
		while (1) {
			int now = s.top();
			if (now == st) st_scc = scc_cnt;
			if (now == t) t_scc = scc_cnt;
			s.pop();
			finished[now] = true;
			scc_num[now] = scc_cnt;
			now_scc.push_back(now);
			if (now == curr) break;
		}
		scc_size[scc_cnt] = now_scc.size();
	}
	return result;
}