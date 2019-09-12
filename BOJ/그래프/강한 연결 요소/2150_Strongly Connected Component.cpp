#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int v, e, cnt;
stack<int> s;
vector<vector<int>> res;
vector<vector<int>> adj;
vector<int> dfsn;
vector<int> fin;
int dfs(int idx);
int main() {
	scanf("%d%d", &v, &e);
	adj.resize(v + 1);
	dfsn.resize(v + 1);
	fin.resize(v + 1);
	for (int i = 1; i <= e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}
	for (int i = 1; i <= v; i++) {
		if (!dfsn[i]) {
			dfs(i);
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("-1\n");
	}
}
int dfs(int idx) {
	dfsn[idx] = ++cnt;
	int result = dfsn[idx];
	s.push(idx);
	for (int i = 0; i < adj[idx].size(); i++) {
		int next = adj[idx][i];
		if (!dfsn[next]) {
			result = min(result, dfs(next));
		}
		else if (!fin[next]) {
			result = min(result, dfsn[next]);
		}
	}
	if (result == dfsn[idx]) {
		vector<int> now;
		while (1) {
			int go = s.top();
			s.pop();
			now.push_back(go);
			fin[go] = 1;
			if (go == idx) break;
		}
		sort(now.begin(), now.end());
		res.push_back(now);
	}
	return result;
}