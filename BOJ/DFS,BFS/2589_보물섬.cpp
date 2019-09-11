#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, res;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
char map[51][51];
int vis[51][51];
queue<pair<int, int>> q;
void bfs(int a, int b);
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vis[i][j] == 0 && map[i][j] == 'L') bfs(i, j);
			memset(vis, 0, sizeof(vis));
		}
	}
	printf("%d\n", res);
}
void bfs(int a, int b) {
	q.push({ a,b });
	vis[a][b] = 1;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		res = max(res, (vis[now.first][now.second] - 1));
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (vis[nx][ny] == 0 && map[nx][ny] == 'L') {
				vis[nx][ny] = (vis[now.first][now.second] + 1);
				q.push({ nx,ny });
			}
		}
	}
}