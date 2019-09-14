#include <iostream>
#include <queue>
using namespace std;
int n, m, vis[101][101], cnt;
int dx[] = { 1,-1,0,0,1,-1,1,-1 };
int dy[] = { 0,0,1,-1,1,-1,-1,1 };
char map[101][101];
queue<pair<int, int>>q;
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '#' && vis[i][j] == 0) {
				q.push(make_pair(i, j));
				vis[i][j] = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 8; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
							if (map[nx][ny] == '#' && vis[nx][ny] == 0) {
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
	printf("%d", cnt);
}