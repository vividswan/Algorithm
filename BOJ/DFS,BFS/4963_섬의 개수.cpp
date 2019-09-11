#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int w, h;
int cnt;
queue<pair<int, int>> q;
int vis[51][51];
int map[51][51];
void bfs(int x, int y);
int dx[] = { 0,0,1,-1 ,1,1,-1,-1 };
int dy[] = { 1,-1,0,0 ,1,-1,1,-1 };
int main(void) {
	while (1) {
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		scanf("%d%d", &w, &h);
		if (w == 0 && h == 0) break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (vis[i][j]) continue;
				if (!map[i][j]) continue;
				cnt++;
				bfs(i, j);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
void bfs(int x, int y) {
	q.push({ x,y });
	vis[x][y] = 1;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx <= 0 || ny <= 0 || nx > h || ny > w) continue;
			if (!map[nx][ny]) continue;
			if (vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}