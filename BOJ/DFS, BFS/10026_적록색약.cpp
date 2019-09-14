#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, vis[102][102];
char map[102][102];
int c_b, c_r, c_g, c_sum;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
int main(void) {
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &map[i][j]);
		}
		getchar();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R' && vis[i][j] == 0) {
				q.push(make_pair(i, j));
				vis[i][j] = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
							if (map[nx][ny] == 'R' && vis[nx][ny] == 0) {
								vis[nx][ny] = 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
				c_r++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'B' && vis[i][j] == 0) {
				q.push(make_pair(i, j));
				vis[i][j] = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
							if (map[nx][ny] == 'B' && vis[nx][ny] == 0) {
								vis[nx][ny] = 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
				c_b++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G' && vis[i][j] == 0) {
				q.push(make_pair(i, j));
				vis[i][j] = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
							if (map[nx][ny] == 'G' && vis[nx][ny] == 0) {
								vis[nx][ny] = 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
				c_g++;
			}
		}
	}
	printf("%d ", c_g + c_r + c_b);
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G' || map[i][j] == 'R') {
				if (vis[i][j] == 0) {
					q.push(make_pair(i, j));
					vis[i][j] = 1;
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int nx = x + dx[i];
							int ny = y + dy[i];
							if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
								if (map[nx][ny] == 'G' || map[nx][ny] == 'R') {
									if (vis[nx][ny] == 0) {
										vis[nx][ny] = 1;
										q.push(make_pair(nx, ny));
									}
								}
							}
						}
					}
					c_sum++;
				}
			}
		}
	}
	printf("%d", c_sum + c_b);
}