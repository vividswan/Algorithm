#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int t, n, m, cnt;
vector<vector<int>> adj;
int dfsn[MAX];
int dfs(int curr);
int scc_cnt;
int in_scc[MAX];
stack<int> s;
bool finished[MAX];
int scc_indegree[MAX];
vector<vector<int>> res;
int main(void) {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		cnt = 0;
		scc_cnt = 0;
		scanf("%d%d", &n, &m);
		memset(dfsn, 0, sizeof(dfsn));
		memset(finished, false, sizeof(finished));
		memset(in_scc, 0, sizeof(in_scc));
		memset(scc_indegree, 0, sizeof(scc_indegree));
		adj.clear();
		adj.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int from, to;
			scanf("%d%d", &from, &to);
			adj[from].push_back(to);
		}
		for (int i = 0; i < n; i++) if(!dfsn[i]) dfs(i);
		for (int i = 0; i < n; i++) {
			for (int next : adj[i]) {
				if (in_scc[next] != in_scc[i]) scc_indegree[in_scc[next]]++;
			}
		}
		int res = 0;
		int res_num;
		for (int i = 1; i <= scc_cnt; i++) {
			if (!scc_indegree[i]) {
				res++;
				res_num = i;
			}
		}
		if (res > 1) printf("Confused\n");
		else  {
			for (int i = 0; i < n; i++) {
				if (in_scc[i] == res_num) printf("%d\n", i);
			}
		}
		printf("\n");
	}
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
			s.pop();
			finished[now] = true;
			in_scc[now] = scc_cnt;
			now_scc.push_back(now);
			if (now == curr) break;
		}
		res.push_back(now_scc);
	}
	return result;
}
