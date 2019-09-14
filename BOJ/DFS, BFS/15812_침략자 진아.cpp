#include <iostream>
#include <queue>
using namespace std;
int n, m, map[21][21], city, res_min;
void bfs(int i, int j, int k, int l);
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) city++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= m; l++) {
					if (i == k && j == l) continue;
					else {
						if (map[i][j] == 0 && map[k][l] == 0) {
							bfs(i, j, k, l);
						}
					}
				}
			}
		}
	}
	printf("%d", res_min);
}
void bfs(int i, int j, int k, int l) {
	int vis[21][21] = { 0, };
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	q.push(make_pair(k, l));
	vis[i][j]++;
	vis[k][l]++;
	int now = 0;
	while (!q.empty()) {
		int l_cnt = q.size();
		for (int i = 0; i < l_cnt; i++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int h = 0; h < 4; h++) {
				int nx = x + dx[h];
				int ny = y + dy[h];
				if (!vis[ny][nx]) {
					if (1 <= nx && nx <= m && 1 <= ny && ny <= n) {
						vis[ny][nx]++;
						if (map[ny][nx] == 1) {
							cnt++;
						}
						q.push(make_pair(ny, nx));
					}
				}
			}
		}
		now++;
		if (cnt == city) {
			if (res_min == 0) res_min = now;
			else if (res_min > now) res_min = now;
			return;
		}
	}
}