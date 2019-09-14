#include <iostream>
#include <algorithm>
using namespace std;
int n, map[501][501], vis[501][501], res, res_map[501][501];
int go(int, int);
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vis[i][j]) {
				go(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res = max(res, res_map[i][j]);
		}
	}
	printf("%d\n", res);
	return 0;
}
int go(int x, int y) {
	if (vis[x][y]) return res_map[x][y];
	vis[x][y] = 1;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 < nx && nx <= n && 0 < ny && ny <= n) {
			if (map[x][y] < map[nx][ny]) {
				cnt++;
				res_map[x][y] = max(go(nx, ny) + 1, res_map[x][y]);
			}
		}
	}
	if (!cnt) return res_map[x][y] = 1;
	else return res_map[x][y];
}