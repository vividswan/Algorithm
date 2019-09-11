#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int cnt, n, m, map[301][301], i_cnt, mn_map[301][301], vis[301][301];
queue<pair<int, int>> q;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void bfs(int i, int j);
void mn_ser(int i, int j);
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		int ed = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j]) {
					ed++;
					mn_ser(i, j);
				}
				if (map[i][j] && !vis[i][j]) {
					bfs(i, j);
					i_cnt++;
				}
				if (i_cnt >= 2) break;
			}
		}
		if (i_cnt >= 2) {
			printf("%d\n", cnt);
			return 0;
		}
		if (ed == 0) {
			printf("0\n");
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				map[i][j] -= mn_map[i][j];
				if (map[i][j] < 0) map[i][j] = 0;
			}
		}
		cnt++;
		ed = 0;
		memset(vis, 0, sizeof(vis));
		memset(mn_map, 0, sizeof(mn_map));
		i_cnt = 0;
	}
}
void mn_ser(int i, int j) {
	int mn_cnt = 0;
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx<1 || ny<1 || nx>n || ny>m) continue;
		if (!map[nx][ny]) mn_cnt++;
	}
	mn_map[i][j] = mn_cnt;
}
void bfs(int i, int j) {
	q.push({ i,j });
	vis[i][j]++;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = now.first + dx[k];
			int ny = now.second + dy[k];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (!vis[nx][ny] && map[nx][ny]) {
				vis[nx][ny]++;
				q.push({ nx,ny });
			}
		}
	}
}