#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m, cnt, map[101][101], pre, roof, vis[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void bfs(int i, int j);
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) cnt++;
		}
	}
	pre = cnt;
	while (cnt) {
		bfs(1, 1);
		memset(vis, 0, sizeof(vis));
	}
	printf("%d\n%d\n", roof, pre);
	return 0;
}
void bfs(int i, int j) {
	pre = cnt;
	queue<pair<int, int>> q;
	q.push({ i, j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (map[nx][ny] == 1) {
				vis[nx][ny] = 1;
				map[nx][ny] = 0;
				cnt--;
				continue;
			}
			if (vis[nx][ny]) continue;
			if (!map[nx][ny]) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
				continue;
			}
		}
	}
	roof++;
}