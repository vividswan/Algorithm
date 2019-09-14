#include <iostream>
#include <queue>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m, map[9][9], map_2[9][9], res;
queue <pair<int, int>> q;
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
			map_2[i][j] = map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) continue;
			for (int k = i; k <= n; k++) {
				for (int l = 1; l <= m; l++) {
					if (i == k && j == l)continue;
					if (map[k][l]) continue;
					for (int a = k; a <= n; a++) {
						for (int b = 1; b <= m; b++) {
							if ((i == a && j == b) || (k == a && l == b))continue;
							if (map[a][b]) continue;
							map[i][j] = 1;
							map[k][l] = 1;
							map[a][b] = 1;
							while (!q.empty()) {
								for (int l = 0; l < q.size(); l++) {
									int x = q.front().first;
									int y = q.front().second;
									q.pop();
									for (int j = 0; j < 4; j++) {
										int nx = x + dx[j];
										int ny = y + dy[j];
										if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
											if (map[nx][ny] == 0) {
												q.push(make_pair(nx, ny));
												map[nx][ny] = 2;
											}
										}
									}
								}
							}
							int cnt = 0;
							for (int i = 1; i <= n; i++) {
								for (int j = 1; j <= m; j++) {
									if (map[i][j] == 0) cnt++;
								}
							}
							if (res < cnt) res = cnt;
							for (int i = 1; i <= n; i++) {
								for (int j = 1; j <= m; j++) {
									map[i][j] = map_2[i][j];
									if (map[i][j] == 2) {
										q.push(make_pair(i, j));
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d", res);
}