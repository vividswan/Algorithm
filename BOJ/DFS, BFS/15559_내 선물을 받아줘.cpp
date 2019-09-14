#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
int dy[] = { 0,-1,1,0 };
int dx[] = { 1,0,0,-1 };
int n, m, cnt, num = 1;
char map[1001][1001];
int vis[1001][1001];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vis[i][j] == 0) {
				q.push({ i, j });
				vis[i][j] = num;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					int go;
					if (map[x][y] == 'S') go = 0;
					else if (map[x][y] == 'W') go = 1;
					else if (map[x][y] == 'E') go = 2;
					else if (map[x][y] == 'N') go = 3;
					int nx = x + dx[go];
					int ny = y + dy[go];
					if (!vis[nx][ny]) {
						vis[nx][ny] = num;
						q.push({ nx,ny });
					}
					else if (vis[nx][ny] == vis[x][y]) cnt++;
				}
				num++;
			}
		}
	}
	printf("%d\n", cnt);
}