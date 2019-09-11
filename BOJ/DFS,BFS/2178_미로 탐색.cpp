#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int map[101][101];
int vis[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0,0 };
queue<pair<int, int>> q;
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	vis[1][1] = 1;
	q.push({ 1,1 });
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (!map[nx][ny]) continue;
			if (vis[nx][ny]) continue;
			vis[nx][ny] = vis[p.first][p.second] + 1;
			q.push({ nx,ny });
		}
	}
	printf("%d\n", vis[n][m]);
	return 0;
}