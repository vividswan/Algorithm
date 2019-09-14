#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
void bfs1(int i, int j);
void bfs2(int i, int j);
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m, vis[101][101], res_1, res_2, real1, real2;
char map[101][101];
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j] && map[i][j] == 'W') bfs1(i, j);
			real1 += res_1 * res_1;
			res_1 = 0;
			if (!vis[i][j] && map[i][j] == 'B') bfs2(i, j);
			real2 += res_2 * res_2;
			res_2 = 0;
		}
	}
	printf("%d %d\n", real1, real2);
	return 0;
}
void bfs1(int i, int j) {
	vis[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });
	while (!q.empty()) {
		auto now = q.front();
		res_1++;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = now.first + dx[k];
			int ny = now.second + dy[k];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (!vis[nx][ny] && map[nx][ny] == 'W') {
				vis[nx][ny]++;
				bfs1(nx, ny);
			}
		}
	}
}
void bfs2(int i, int j) {
	vis[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });
	while (!q.empty()) {
		auto now = q.front();
		res_2++;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = now.first + dx[k];
			int ny = now.second + dy[k];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (!vis[nx][ny] && map[nx][ny] == 'B') {
				vis[nx][ny]++;
				bfs2(nx, ny);
			}
		}
	}
}