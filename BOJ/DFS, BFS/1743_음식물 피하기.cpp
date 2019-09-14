#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, k;
int maxx;
int map[101][101];
int vis[101][101];
void bfs(int a, int b);
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) continue;
			if (vis[i][j]) continue;
			vis[i][j] = 1;
			bfs(i, j);
		}
	}
	printf("%d\n", maxx);
}
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	int size = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		size++;
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (vis[nx][ny]) continue;
			if (map[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	maxx = max(maxx, size);
}