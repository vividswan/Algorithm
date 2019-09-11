#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int>> q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int num, cnt, map[27][27], vis[27][27], check, res[626];
int main(void) {
	cin >> num;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (vis[i][j] == 0 && map[i][j] == 1) {
				q.push(make_pair(i, j));
				vis[i][j] = 1;
				check++;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 1 && ny >= 1 && nx <= num && ny <= num) {
							if (vis[nx][ny] == 0 && map[nx][ny] == 1) {
								q.push(make_pair(nx, ny));
								vis[nx][ny] = 1;
								check++;
							}
						}
					}
				}
				cnt++;
				res[cnt] = check;
				check = 0;
			}
		}
	}
	sort(res, res + cnt + 1);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}