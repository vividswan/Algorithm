#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
queue<pair<pair<int, int>, int>> q;
int m, n, map[1001][1001], cnt, res;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push({ {i,j},0 });
			}
			else if (map[i][j] == 0) cnt++;
		}
	}
	while (!q.empty()) {
		int si = q.size();
		for (int i = 1; i <= si; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int roof = q.front().second;
			res = max(roof, res);
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<1 || ny<1 || nx>n || ny>m) continue;
				if (map[nx][ny] == 0) {
					map[nx][ny] = 1;
					cnt--;
					q.push({ {nx,ny},roof + 1 });
				}
			}
		}
	}
	if (!cnt) printf("%d", res);
	else printf("-1");
}