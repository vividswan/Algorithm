#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n, m;
double s, v;
pair<double, double> mouse[101];
pair<double, double> go[101];
int adj[101][101];
int vis[101];
int m_adj[101];
int g_adj[101];
int res;
bool pos(int i, int j);
double dist(int i, int j);
bool dfs(int idx);
int main(void) {
	scanf("%d%d%lf%lf", &n, &m, &s, &v);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &mouse[i].first, &mouse[i].second);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lf%lf", &go[i].first, &go[i].second);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (pos(i, j)) {
				adj[i][j] = 1;
			}
		}
	}
	memset(m_adj, -1, sizeof(m_adj));
	memset(g_adj, -1, sizeof(g_adj));
	for (int i = 1; i <= n; i++) {
		memset(vis, -1, sizeof(vis));
		if (dfs(i)) res++;
	}
	printf("%d\n", n - res);
	return 0;
}
bool pos(int i, int j) {
	double di = dist(i, j);
	if (s >= (di / v)) return true;
	return false;
}
double dist(int i, int j) {
	double x = pow((mouse[i].first - go[j].first), 2.0);
	double y = pow((mouse[i].second - go[j].second), 2.0);
	double res = sqrt(x + y);
	return res;
}
bool dfs(int idx) {
	if (vis[idx] != -1) return false;
	vis[idx] = 1;
	for (int i = 1; i <= m; i++) {
		if (adj[idx][i]) {
			if (g_adj[i] == -1 || dfs(g_adj[i])) {
				m_adj[idx] = i;
				g_adj[i] = idx;
				return true;
			}
		}
	}
	return false;
}