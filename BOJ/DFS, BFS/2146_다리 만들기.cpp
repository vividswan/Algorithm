#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int map[101][101];
int vis[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int cnt = 1;
int land_num[101][101];
int adj_num[101][101];
int minn = 100000;
queue<pair<int, int>> go;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!map[i][j]) continue;
			if (vis[i][j]) continue;
			queue<pair<int, int>> q;
			q.push({ i,j });
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				land_num[x][y] = cnt;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx<1 || ny<1 || nx>n || ny>n) continue;
					if (!map[nx][ny]) {
						adj_num[nx][ny] = cnt;
						go.push({ nx,ny });
						continue;
					}
					if (vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			cnt++;
		}
	}
	while (!go.empty()) {
		int x = go.front().first;
		int y = go.front().second;
		go.pop();
		memset(vis, 0, sizeof(vis));
		queue<pair<int, int>> go_q;
		go_q.push({ x,y });
		vis[x][y] = 1;
		int swc = 0;
		int now_adj_num = adj_num[x][y];
		while (!go_q.empty()) {
			if (swc) break;
			int now_x = go_q.front().first;
			int now_y = go_q.front().second;
			go_q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = now_x + dx[i];
				int ny = now_y + dy[i];
				if (nx<1 || ny<1 || nx>n || ny>n) continue;
				if (vis[nx][ny]) continue;
				if (now_adj_num == land_num[nx][ny]) continue;
				if (land_num[nx][ny] != 0) {
					if (now_adj_num != land_num[nx][ny]) {
						minn = min(minn, vis[now_x][now_y]);
						swc++;
					}
				}
				vis[nx][ny] = vis[now_x][now_y] + 1;
				go_q.push({ nx,ny });
			}
		}
	}
	printf("%d\n", minn);
	return 0;
}