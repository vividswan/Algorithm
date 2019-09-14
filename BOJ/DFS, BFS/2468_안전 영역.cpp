#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
queue<pair<int, int>> q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int num, cnt, map[105][105], vis[105][105], res[105];
int main(void) {
	cin >> num;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int max = 0;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (max < map[i][j]) max = map[i][j];
		}
	}
	for (int k = 0; k < max; k++) {
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				if (vis[i][j] == 0 && map[i][j] > k) {
					q.push(make_pair(i, j));
					vis[i][j] = 1;
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int nx = x + dx[i];
							int ny = y + dy[i];
							if (nx >= 1 && ny >= 1 && nx <= num && ny <= num) {
								if (vis[nx][ny] == 0 && map[nx][ny] > k) {
									q.push(make_pair(nx, ny));
									vis[nx][ny] = 1;
								}
							}
						}
					}
					cnt++;
				}
			}
		}
		res[k] = cnt;
		cnt = 0;
		memset(vis, 0, sizeof(vis));
	}
	sort(res, res + max);
	printf("%d\n", res[max - 1]);
	return 0;
}