#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 5001;
vector<vector<int>> adj;
vector<vector<int>> scc;
int outdegree[MAX];
stack<int> s;
int cnt;
priority_queue<int, vector<int>, greater<>> pq;
int dfsn[MAX];
bool finished[MAX];
int now_scc_num;
int scc_num[MAX];
int dfs(int curr);
int main(void) {
	while (1) {
		int n, m;
		scanf("%d", &n);
		if (n == 0) break;
		memset(dfsn, 0, sizeof(dfsn));
		memset(finished, false, sizeof(finished));
		memset(outdegree, 0, sizeof(outdegree));
		memset(scc_num, 0, sizeof(scc_num));
		cnt = 0;
		now_scc_num = 0;
		adj.clear();
		scc.clear();
		adj.resize(n + 1);
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			int from, to;
			scanf("%d%d", &from, &to);
			adj[from].push_back(to);
			outdegree[from]++;
		}
		for (int i = 1; i <= n; i++) if (!dfsn[i]) dfs(i);
		for (auto& p : scc) {
			int swc = 0;
			for (int next : p) {
				if (outdegree[next] >= 1) {
					for (int swc_next : adj[next]) {
						if (scc_num[next] != scc_num[swc_next]) {
							swc++;
							break;
						}
					}
				}
			}
			if (swc == 0) for (int next : p) pq.push(next);
		}
		while (!pq.empty()) {
			int now = pq.top();
			pq.pop();
			printf("%d ", now);
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
		now_scc_num++;
		vector<int> now_scc;
		while (1) {
			int now = s.top();
			s.pop();
			scc_num[now] = now_scc_num;
			finished[now] = true;
			now_scc.push_back(now);
			if (now == curr) break;
		}
		scc.push_back(now_scc);
	}
	return result;
}