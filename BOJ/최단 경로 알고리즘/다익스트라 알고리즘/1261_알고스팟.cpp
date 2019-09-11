#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int map[101][101], dist[101][101], vis[101][101];
int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = 12345678;
		}
	}
	dist[1][1] = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{1,1} });
	while (!pq.empty()) {
		int x, y, val;
		do {
			val = pq.top().first;
			x = pq.top().second.first;
			y = pq.top().second.second;
			pq.pop();
		} while (!pq.empty() && vis[x][y]);
		if (vis[x][y]) continue;
		vis[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (vis[nx][ny]) continue;
			if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
				dist[nx][ny] = dist[x][y] + map[nx][ny];
				pq.push({ dist[nx][ny],{nx,ny} });
			}
		}
	}
	printf("%d\n", dist[n][m]);
}