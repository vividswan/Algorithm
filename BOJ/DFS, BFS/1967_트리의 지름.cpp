#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int nod, vis[10001], len, max_len = 0, st;
vector<pair<int, int>> adj[10001];
void dfs(int);
int main(void) {
	cin >> nod;
	for (int i = 1; i < nod; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	dfs(1);
	memset(vis, 0, sizeof(vis));
	max_len = 0;
	dfs(st);
	printf("%d", max_len);
}
void dfs(int x) {
	int now = x;
	if (len > max_len) {
		max_len = len;
		st = x;
	}
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i].first;
		if (!vis[next]) {
			vis[next] = 1;
			len += adj[now][i].second;
			dfs(next);
			vis[next] = 0;
			len -= adj[now][i].second;
		}
	}
}