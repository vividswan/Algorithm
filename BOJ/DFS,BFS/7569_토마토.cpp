#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dh[] = { 1,-1 };
int map[102][102][102], vis[102][102][102], cnt, res;
queue<pair<int, pair<int, int>>> q;
int main(void) {
	int m, n, h;
	cin >> m >> n >> h;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[k][i][j];
				if (map[k][i][j] == 0) cnt++;
				if (map[k][i][j] == 1) {
					q.push({ k,{i,j} });
					vis[k][i][j] = 1;
				}
			}
		}
	}
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nh = now.first;
			int nx = now.second.first + dx[i];
			int ny = now.second.second + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (map[nh][nx][ny] == 1) continue;
			if (map[nh][nx][ny] == -1) continue;
			if (!vis[nh][nx][ny]) {
				vis[nh][nx][ny] = vis[now.first][now.second.first][now.second.second] + 1;
				res = max(res, vis[nh][nx][ny] - 1);
				cnt--;
				q.push({ nh,{nx,ny} });
			}
		}
		for (int i = 0; i < 2; i++) {
			int nh = now.first + dh[i];
			int nx = now.second.first;
			int ny = now.second.second;
			if (nh<1 || nh>h) continue;
			if (map[nh][nx][ny] == 1) continue;
			if (map[nh][nx][ny] == -1) continue;
			if (!vis[nh][nx][ny]) {
				vis[nh][nx][ny] = vis[now.first][now.second.first][now.second.second] + 1;
				res = max(res, vis[nh][nx][ny] - 1);
				cnt--;
				q.push({ nh,{nx,ny} });
			}
		}
	}
	if (!cnt) cout << res << '\n';
	else cout << -1 << '\n';
}