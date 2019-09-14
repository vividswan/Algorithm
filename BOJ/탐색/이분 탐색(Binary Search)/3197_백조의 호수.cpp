#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
char map[1501][1501];
int vis[1501][1501];
int now_vis[1501][1501];
vector<pair<int, int>> v;
void bfs(void);
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int r, c;
int le = 0;
int ri = 1500 * 2 + 1;
int res_max = 0;
queue<pair<int, int>> q;
int main(void) {
	memset(vis, -1, sizeof(vis));
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '.') {
				vis[i][j] = 0;
				q.push({ i,j });
				now_vis[i][j] = 1;
			}
			else if (map[i][j] == 'L') {
				v.push_back({ i,j });
				vis[i][j] = 0;
				q.push({ i,j });
				now_vis[i][j] = 1;
			}
		}
	}
	bfs();
	ri = res_max;
	while (le <= ri) {
		memset(now_vis, 0, sizeof(now_vis));
		now_vis[v[0].first][v[0].second] = 1;
		int swc = 0;
		int mi = (le + ri) / 2;
		queue<pair<int, int>> res;
		res.push({ v[0].first,v[0].second });
		while (!res.empty()) {
			int x = res.front().first;
			int y = res.front().second;
			res.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<1 || ny<1 || nx>r || ny>c) continue;
				if (nx == v[1].first && ny == v[1].second) {
					swc++;
					break;
				}
				if (vis[nx][ny] > mi) continue;
				if (now_vis[nx][ny]) continue;
				now_vis[nx][ny] = 1;
				res.push({ nx,ny });
			}
		}
		if (swc) ri = mi - 1;
		else le = mi + 1;
	}
	printf("%d\n", le);
}
void bfs(void) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>r || ny>c) continue;
			if (map[nx][ny] == 'L') continue;
			if (now_vis[nx][ny]) continue;
			if (vis[nx][ny] == -1) {
				vis[nx][ny] = vis[x][y] + 1;
				res_max = max(res_max, vis[nx][ny]);
				now_vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}