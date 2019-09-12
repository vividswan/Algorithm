#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
int vis[51];
int adj[51][51];
int s_adj[51];
vector<long long> s[51];
bool dfs(int idx);
int res;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		s[i].push_back(a);
		s[i].push_back(b);
		s[i].push_back(c);
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (s[i][0] == s[j][0] && s[i][1] == s[j][1] && s[i][2] == s[j][2]) {
				adj[i][j] = 1;
				continue;
			}
			if (s[i][0] >= s[j][0] && s[i][1] >= s[j][1] && s[i][2] >= s[j][2]) adj[i][j] = 1;
			if (s[i][0] <= s[j][0] && s[i][1] <= s[j][1] && s[i][2] <= s[j][2]) adj[j][i] = 1;
		}
	}
	memset(s_adj, -1, sizeof(s_adj));
	for (int k = 1; k <= 2; k++) {
		for (int i = 1; i <= n; i++) {
			memset(vis, -1, sizeof(vis));
			if (dfs(i)) res++;
		}
	}
	printf("%d\n", n - res);
	return 0;
}
bool dfs(int idx) {
	if (vis[idx] != -1) return false;
	vis[idx]++;
	for (int i = 1; i <= n; i++) {
		if (adj[idx][i]) {
			if (s_adj[i] == -1 || dfs(s_adj[i])) {
				s_adj[i] = idx;
				return true;
			}
		}
	}
	return false;
}