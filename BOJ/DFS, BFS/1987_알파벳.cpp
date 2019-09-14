#include <iostream>
#include <algorithm>
using namespace std;
int chk[21][21];
int r, c;
int vis[30];
int map[21][21];
void dfs(int x, int y, int cnt);
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int maxx;
int main(void) {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char a;
			scanf(" %c", &a);
			map[i][j] = a - 'A';
		}
	}
	vis[map[1][1]] = 1;
	dfs(1, 1, 1);
	printf("%d\n", maxx);
}
void dfs(int x, int y, int cnt) {
	maxx = max(cnt, maxx);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > r || ny > c) continue;
		if (vis[map[nx][ny]]) continue;
		vis[map[nx][ny]] = 1;
		dfs(nx, ny, cnt + 1);
		vis[map[nx][ny]] = 0;
		;
	}
}