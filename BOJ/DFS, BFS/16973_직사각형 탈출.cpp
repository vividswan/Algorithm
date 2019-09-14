#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001], vis[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	int n, m, h, w, sr, sc, fr, fc;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> h >> w >> sr >> sc >> fr >> fc;
	queue<pair<int, int>>q;
	vis[sr][sc] = 1;
	q.push({ sr,sc });
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m || nx + h - 1 > n || ny + w - 1 > m) continue;
			int swc = 0;
			for (int i = nx; i <= nx + h - 1; i++) {
				if (swc) break;
				if (i == nx || i == nx + h - 1) {
					for (int j = ny; j <= ny + w - 1; j++) {
						if (map[i][j] == 1) {
							swc++;
							break;
						}
					}
				}
				else {
					if (map[i][ny] == 1 || map[i][ny + w - 1] == 1) {
						swc++;
						break;
					}
				}
			}
			if (swc) continue;
			if (!vis[nx][ny]) {
				vis[nx][ny] = vis[now.first][now.second] + 1;
				q.push({ nx,ny });
			}
		}
	}
	if (!vis[fr][fc]) printf("-1\n");
	else printf("%d\n", vis[fr][fc] - 1);
}