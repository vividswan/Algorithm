#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k, m, p, res = 1;
		int indegree[1001] = { 0, };
		int cnt[1001] = { 0, };
		int val[1001] = { 0, };
		int pre_val[1001] = { 0, };
		vector<vector<int>>adj;
		queue<int>q;
		scanf("%d%d%d", &k, &m, &p);
		adj.resize(m + 1);
		for (int i = 1; i <= p; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			indegree[b]++;
		}
		for (int i = 1; i <= m; i++) {
			if (!indegree[i]) {
				val[i] = 1;
				q.push(i);
			}
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now][i];
				int now_preval = pre_val[next];
				pre_val[next] = max(pre_val[next], val[now]);
				if (now_preval != pre_val[next]) cnt[next] = 1;
				else cnt[next]++;
				indegree[next]--;
				if (!indegree[next]) {
					q.push(next);
					if (cnt[next] > 1) val[next] = pre_val[next] + 1;
					else val[next] = pre_val[next];
					res = max(res, val[next]);
				}
			}
		}
		printf("%d %d\n", k, res);
	}
}