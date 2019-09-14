#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int c, r, k, cnt;
int map[1001][1001];
int vis[1001][1001];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
queue<pair<int, int>> q;
int main(void) {
	scanf("%d%d%d", &c, &r, &k);
	if (k > c * r) {
		printf("%d\n", 0);
		return 0;
	}
	while (k > 2 * (c + r) - 4) {
		k -= 2 * (c + r) - 4;
		c -= 2;
		r -= 2;
		cnt++;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (i == 1 || i == r) {
				map[i][j] = 1;
				continue;
			}
			if (j == 1) {
				map[i][j] = 1;
				continue;
			}
			if (j == c) {
				map[i][j] = 1;
				continue;
			}
		}
	}
	q.push({ 1,1 });
	vis[1][1] = 1;
	int res_x;
	int res_y;
	while (!q.empty()) {
		k--;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (k == 0) {
			res_x = x;
			res_y = y;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>r || ny>c) continue;
			if (vis[nx][ny]) continue;
			if (map[nx][ny] == 1) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
				break;
			}
		}
	}
	printf("%d %d\n", cnt + res_y, cnt + res_x);
}