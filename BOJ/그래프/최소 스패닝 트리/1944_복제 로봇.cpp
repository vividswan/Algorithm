#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, cnt, map[51][51], vis_map[51][51], vis[252], key_map[51][51];
vector<pair<int, int>> loc;
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
queue<pair<int, int>>q;
queue<pair<int, int>>bfs;
void go(int a, int b);
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void prim(int idx);
int res;
int main(void) {
	scanf("%d%d", &n, &m);
	adj.resize(m + 1);
	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') {
				q.push({ i,j });
			}
		}
	}
	go(q.front().first, q.front().second);
	if (cnt != m) {
		printf("%d\n", -1);
		return 0;
	}
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		loc.push_back({ p.first,p.second });
	}
	for (int i = 0; i <= m; i++) {
		int now_x = loc[i].first;
		int now_y = loc[i].second;
		queue<pair<int, int>> cq;
		cq.push({ now_x,now_y });
		int chk[51][51] = { 0, };
		chk[now_x][now_y] = 1;
		while (!cq.empty()) {
			auto a = cq.front();
			cq.pop();
			int x = a.first;
			int y = a.second;
			if (map[x][y] == 'S' || map[x][y] == 'K') {
				if (i != key_map[x][y]) adj[i].push_back({ chk[x][y] - 1, key_map[x][y] });
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx > n || ny > n || nx < 1 || ny < 1) continue;
				if (!chk[nx][ny] && map[nx][ny] != '1') {
					chk[nx][ny] = chk[x][y] + 1;
					cq.push({ nx,ny });
				}
			}
		}
	}
	prim(0);
	printf("%d\n", res);
	return 0;
}
void go(int x, int y) {
	bfs.push({ x,y });
	vis_map[x][y] = 1;
	while (!bfs.empty()) {
		int now_x = bfs.front().first;
		int now_y = bfs.front().second;
		bfs.pop();
		if (map[now_x][now_y] == 'K') {
			cnt++;
			q.push({ now_x,now_y });
			key_map[now_x][now_y] = cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = now_x + dx[i];
			int ny = now_y + dy[i];
			if (nx > n || ny > n || nx < 1 || ny < 1) continue;
			if (!vis_map[nx][ny] && map[nx][ny] != '1') {
				vis_map[nx][ny] = 1;
				bfs.push({ nx,ny });
			}
		}
	}
}
void prim(int idx) {
	vis[idx] = 1;
	for (auto p : adj[idx]) {
		if (!vis[p.second]) {
			pq.push({ p.first,p.second });
		}
	}
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (!vis[p.second]) {
			res += p.first;
			prim(p.second);
			return;
		}
	}
}