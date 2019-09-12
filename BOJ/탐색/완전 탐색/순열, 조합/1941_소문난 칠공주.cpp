#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
char map[6][6];
int s_chk[26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int cnt_m = 1;
void go(int idx, int cnt);
int chk[26];
int res, swc;
void go_res();
int lot[26][26];
vector<pair<int, int>> v;
int main(void) {
	v.resize(26);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'S') s_chk[cnt_m] = 1;
			lot[i][j] = cnt_m;
			v[cnt_m] = { i,j };
			cnt_m++;
		}
	}
	go(1, 1);
	printf("%d\n", res);
}
void go(int idx, int cnt) {
	if (cnt == 8) {
		int das = 0;
		swc = 0;
		for (int i = 1; i <= 25; i++) {
			if (chk[i]) {
				if (s_chk[i]) {
					das++;
					if (!swc) swc = i;
				}
			}
		}
		if (das >= 4) go_res();
		return;
	}
	for (int i = idx; i <= 25; i++) {
		if (chk[i]) continue;
		chk[i] = 1;
		go(i, cnt + 1);
		chk[i] = 0;
	}
}
void go_res(void) {
	int go = 0;
	int vis[26][26];
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int>> q;
	q.push({ v[swc].first, v[swc].second });
	vis[v[swc].first][v[swc].second] = 1;
	while (!q.empty()) {
		go++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx>5 || ny>5) continue;
			if (vis[nx][ny]) continue;
			if (chk[lot[nx][ny]] == 1) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	if (go == 7) {
		res++;
	}
}