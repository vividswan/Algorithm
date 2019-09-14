#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, vis[51][51][64], res;
char map[51][51];
queue<pair<pair<int, int>, int>> q;
void bfs(void);
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '0') {
				q.push({ { i,j }, 0 });
			}
		}
	}
	bfs();
	return 0;
}
void bfs(void) {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		if (map[x][y] == '1') {
			printf("%d\n", vis[x][y][cnt]);
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int n_cnt = cnt;
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (vis[nx][ny][cnt] || map[nx][ny] == '#') continue;
			if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F') {
				if (!(cnt & (1 << map[nx][ny] - 'A'))) continue;
			}
			if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
				n_cnt |= (1 << (map[nx][ny] - 'a'));
			}
			q.push({ {nx,ny},n_cnt });
			vis[nx][ny][n_cnt] = vis[x][y][cnt] + 1;
		}
	}
	printf("%d\n", -1);
}