#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>map(8, vector<int>(8));
vector<vector<int>>vis(8, vector<int>(8));
int result;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y) {
	if (x == 7 && y == 7) {
		result++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx>7 || ny < 1 || ny>7) continue;
		if (map[nx][ny] == 1) continue;
		if (!vis[nx][ny]) {
			vis[nx][ny] = true;
			dfs(nx, ny);
			vis[nx][ny] = false;
		}
	}
}
int main(void) {
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			cin >> map[i][j];
		}
	}
	vis[1][1] = true;
	dfs(1, 1);
	cout << result << '\n';
	return 0;
}