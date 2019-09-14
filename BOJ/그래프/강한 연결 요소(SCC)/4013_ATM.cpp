#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define max_cross 500010
using namespace std;
long long val[max_cross];
int fin[max_cross];
int dfsn[max_cross];
int in_scc[max_cross];
int ed[max_cross];
int ed_scc[max_cross];
int indegree[max_cross];
long long res_scc[max_cross];
int st_scc;
long long scc_val[max_cross];
long long res = 0;
int vis[max_cross];
void go(int idx);
queue<int> go_st;
int dfs(int idx);
queue<int> q;
vector<vector<int>> scc_adj;
vector<vector<int>> adj;
int n, m, cnt, scc_num, st;
stack<int> s;
int main() {
	scanf("%d%d", &n, &m);
	adj.resize(n + 1);
	scc_adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		long long a;
		scanf("%lld", &a);
		val[i] = a;
	}
	int num;
	scanf("%d%d", &st, &num);
	for (int i = 0; i < num; i++) {
		int a;
		scanf("%d", &a);
		ed[a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (dfsn[i] == 0) dfs(i);
	}
	int swc = 0;
	go(st);
	while (!go_st.empty()) {
		int i = go_st.front();
		go_st.pop();
		for (int j = 0; j < adj[i].size(); j++) {
			int next = adj[i][j];
			if (in_scc[i] != in_scc[next]) {
				scc_adj[in_scc[i]].push_back(in_scc[next]);
				indegree[in_scc[next]]++;
			}
		}
	}
	q.push(st_scc);
	res_scc[st_scc] = scc_val[st_scc];
	res = scc_val[st_scc];
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (ed_scc[now]) res = max(res, res_scc[now]);
		for (int i = 0; i < scc_adj[now].size(); i++) {
			int next = scc_adj[now][i];
			indegree[next]--;
			res_scc[next] = max(res_scc[next], res_scc[now] + scc_val[next]);
			if (indegree[next] == 0) q.push(next);
		}
	}
	printf("%lld\n", res);
}
int dfs(int idx) {
	dfsn[idx] = ++cnt;
	int result = dfsn[idx];
	s.push(idx);
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (dfsn[next] == 0) result = min(result, dfs(next));
		else if (fin[next] == 0) result = min(result, dfsn[next]);
	}
	if (result == dfsn[idx]) {
		while (1) {
			int now = s.top();
			s.pop();
			fin[now] = 1;
			in_scc[now] = scc_num;
			scc_val[scc_num] += val[now];
			if (now == st) st_scc = scc_num;
			if (ed[now]) ed_scc[scc_num] = 1;
			if (now == idx) break;
		}
		scc_num++;
	}
	return result;
}
void go(int idx) {
	if (vis[idx]) return;
	vis[idx] = 1;
	go_st.push(idx);
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (vis[next] == 0) go(next);
	}
}