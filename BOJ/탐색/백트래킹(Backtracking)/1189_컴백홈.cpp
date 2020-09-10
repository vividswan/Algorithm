#include <iostream>
#include <vector>
using namespace std;
char map[6][6];
bool vis[6][6];
int r, c, k;
int result;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y, int cnt) {
	if (cnt == k) {
		if (x == 1 && y == c) result++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx>r || ny>c) continue;
		if (map[nx][ny] == 'T') continue;
		if (vis[nx][ny] == false) {
			vis[nx][ny] = true;
			dfs(nx, ny, cnt + 1);
			vis[nx][ny] = false;
		}
	}
}
int main(void) {
	cin >> r >> c >> k;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			vis[i][j] = false;
		}
	}
	vis[r][1] = true;
	dfs(r, 1, 1);
	cout << result << '\n';
	return 0;
}