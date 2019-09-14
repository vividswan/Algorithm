#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
char map[1003][1003];
int vis[1003][1003];
int res2_vis[1003][1003];
int n;
void bfs(int i, int j);
int res1, res2;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == '.') continue;
			if (vis[i][j]) continue;
			bfs(i, j);
		}
	}
	printf("%d %d\n", res1, res2);
}
void bfs(int i, int j) {
	int now_res1 = 0;
	int now_res2 = 0;
	queue<pair<int, int>> q;
	q.push({ i,j });
	vis[i][j] = 1;
	while (!q.empty()) {
		now_res1++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx<0 || ny<0 || nx>n + 1 || ny>n + 1) continue;
			if (vis[nx][ny]) continue;
			if (map[nx][ny] != '#') {
				now_res2++;
				continue;
			}
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	if (now_res1 == res1) {
		res2 = min(now_res2, res2);
	}
	else if (now_res1 > res1) {
		res1 = now_res1;
		res2 = now_res2;
	}
}