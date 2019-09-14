#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> v;
void dfs(int idx);
int par[100001];
int vis[100001];
int main(void) {
	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", par[i]);
	}
	return 0;
}
void dfs(int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		int next = v[idx][i];
		if (vis[next]) continue;
		par[next] = idx;
		vis[next] = 1;
		dfs(next);
	}
}