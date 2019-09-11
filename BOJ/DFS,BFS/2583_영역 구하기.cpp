#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int vis[101][101];
int map[101][101];
int m, n, k;
vector<int> ans;
void bfs(int i, int j);
int main(void) {
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 1; i <= k; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for (int k = a + 1; k <= c; k++) {
			for (int m = b + 1; m <= d; m++) {
				map[m][k] = 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (vis[i][j] == 0) {
				if (map[i][j]) continue;
				vis[i][j] = 1;
				bfs(i, j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
void bfs(int i, int j) {
	int res = 0;
	queue<pair<int, int>>q;
	q.push({ i,j });
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		res++;
		int x = p.first;
		int y = p.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx<1 || ny<1 || nx>m || ny>n) continue;
			if (map[nx][ny] == 1) continue;
			if (vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	ans.push_back(res);
}